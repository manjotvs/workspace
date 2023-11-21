#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char *
strerr (int errnoval)
{
  const char *msg;
  static char buf[32];
  if(1)
    {
      /* In range, but no sys_errlist or no entry at this index. */
      sprintf (buf, "Error %d", errnoval);
      msg = buf;
    }
  else
    {
      /* In range, and a valid message.  Just return the message. */
      msg = (char *) sys_errlist[errnoval];
    }
  
  return (msg);
}

static char *GetErrorString(int x)
{
   static char errorString[20];

   switch ( x )
   {
       case 0:
           //errorString = "Success -- No error.";
          snprintf (errorString, 20, "Success -- No error.");
           break;
       case 2:
           //errorString = "Overflow!";
           snprintf (errorString, 20, "Overflow!");
           break;
       default:
         return NULL;
      
   }
   return errorString;
}


/*
* This is a circular buffer that allows enqueue or dequeue arbitrary
* amount of bytes. The buffer size is limited to BUF_SIZE.
*/

static char *GetErrorString(int x);

#define BUF_SIZE    8

typedef struct {
   int write_index;
   int read_index;
   char *buf;
   int size;
   bool full;
} circular_buf_t;

circular_buf_t buf;

int getCurrentBufferSize() 
{
  int size = buf.size;

  if(!buf.full)
  {
    if(buf.write_index >= buf.read_index)
    {
      size = (buf.write_index  - buf.read_index);
    }
    else
    {
      size = (buf.size + buf.write_index  - buf.read_index );
    }
  }
  return size;
}

bool isCurrentBufferEmpty()
{
  return (!buf.full && (buf.write_index == buf.read_index));
}

/*
* Enqueue (size) bytes from (client_buf) to the local buf
* memory of (client_buf) is allocated by the caller
*/
int enqueue(char *client_buf, int size)
{
  if (size > BUF_SIZE) {
    printf("%s", GetErrorString(3));
    return 3;
  }
  /* Assuming buffer stale data can be overwritten by new data */
  int part1 = buf.size - buf.write_index; //changed
  if(size > part1 )
  {
    printf("\nAdd1: %d\n",part1);
    memcpy(buf.buf + buf.write_index, client_buf, part1);
    int part2 = size - part1;
    memcpy(buf.buf, client_buf+part1, part2);

    // Handle the case when sum of new and exiting elements will be greater than buffer size.
    if((getCurrentBufferSize() + size) > buf.size)
    {
      if(buf.read_index <= buf.write_index)
      {
        buf.read_index = part2;
      }
      // For full buffer - R = 7 n W = 3 for n = 8, fill [1,2,3,4,5,6]
      else if(buf.read_index > buf.write_index)
      {
        buf.read_index = part2;
      }
    } 
    buf.write_index = part2;
  }
  else
  { 
    printf("\nAdd2\n");
    memcpy(buf.buf + buf.write_index, client_buf, size);
    if(((size == part1) && (buf.read_index > buf.write_index) ) || buf.full == 1)// Equal number of elements and ava
      buf.read_index = buf.write_index =  (buf.write_index + size) % buf.size;
    else
    {
      if((getCurrentBufferSize() + size) > buf.size) 
      {
        buf.read_index = (buf.write_index + size) % buf.size;
      }
      buf.write_index =  (buf.write_index + size) % buf.size;

    }
   
  }
  if(buf.read_index == buf.write_index)
  {
    buf.full = 1;
  }
  return 0;
}

/*
* Dequeue (size) bytes from the local buf to (client_buf),
* (client_buf) is allocated by the caller. It is okay to assume
* (client_buf) is big enough to hold all the (size) bytes
*/
int dequeue(char *client_buf, int size)
{
  if (size > BUF_SIZE) {
    printf("%s", GetErrorString(2));
    return 2;
  }

  if(isCurrentBufferEmpty())
    return -1;

  int available_size = getCurrentBufferSize();
  if(available_size < size)
  {
    printf("Unavailable \n");
    return -1;
  }

  if(buf.read_index < buf.write_index)
  {
    printf("hi\n");
    memcpy(client_buf, buf.buf + buf.read_index, size);
    buf.read_index += size;
  }
  else
  {
    int part1 = buf.size - ( buf.read_index);
    if(size <= part1)
    {
      printf("ssa: %d\n",size);
      memcpy(client_buf, buf.buf + buf.read_index, size);
      buf.read_index = buf.read_index + size;

    }
    else
    {
       printf("hello: %d\n",part1);
       memcpy(client_buf, buf.buf + buf.read_index, part1);
       int part2 = size - part1;
       memcpy(client_buf+part1, buf.buf, part2);
       buf.read_index = part2;
    }
  }
  buf.full = false;
  return 0;
}

void display_buffer()
{
  int r = buf.read_index;
  int w = buf.write_index;
  int elements = 0;
  int i = buf.read_index;
  elements = getCurrentBufferSize();
  printf("Read Index: %d\n",r);
  printf("Write Index: %d\n",w);
  printf("Elements: %d\n",elements);
  int j=0;
  while(j < elements)
  {
    //printf("%d ",buf.buf[i]);
    printf("Pos[%d]: %d ",i,buf.buf[i]);
    i = (i+1)%BUF_SIZE;
    j++;
  }
  printf("\n");
}

void dis(int n)
{
 printf("\nReading buffer\n");
  char read_buffer[20];
  if(dequeue(read_buffer, n)==-1)
    return;
   int r = buf.read_index;
  int w = buf.write_index;
  printf("Read Index: %d\n",r);
  printf("Write Index: %d\n",w);
  printf("ReadBuffeer: ");
  for(int i =0; i<n;i++)
    printf("%d ", read_buffer[i] );
  printf("\n");
}

int main(int argc,char* argv[])
{
  // initialize buffer
  buf.buf = malloc(BUF_SIZE);
  buf.size = BUF_SIZE;
  buf.write_index = 0;
  buf.read_index = 0;
  buf.full = 0;

  char sample[] = {1,2,3};
  enqueue(sample, sizeof(sample)/sizeof(char));
  display_buffer();

  char sample1[] = {7,8,9,10,11};
  enqueue(sample1, sizeof(sample1)/sizeof(char));
  display_buffer();
  printf("Is buffer full: %d\n", buf.full);
  
  dis(5);

  char sample2[] = {17,18,19,20,21,22};
  enqueue(sample2, sizeof(sample2)/sizeof(char));
  display_buffer();

  dis(4);

  char sample6[] = {123,124,125,126};
  enqueue(sample6, sizeof(sample6)/sizeof(char));
  display_buffer();

  dis(4);

  char sample3[] = {-21};
  enqueue(sample3, sizeof(sample3)/sizeof(char));
  display_buffer();

  char sample4[] = {-28};
  enqueue(sample4, sizeof(sample4)/sizeof(char));
  display_buffer();

  char sample5[] = {-119};
  enqueue(sample5, sizeof(sample5)/sizeof(char));
  display_buffer();

dis(3);
  


  // Perform enqueue() and dequeue();

  // All completed, return
  return 0;
}
