#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Review Comments
  As per my analysis, I have provided comments below where more attention is needed. Also, this code doesn't support 
  the multithreading environment.

    To do:
    1) Please provide more information for the circular buffer design and add all the assumptions made
       to develop this code.
    2) I have added comments below for all possible improvements but proper design documentation will be required for final review. 
    3) Handle cases like
       a) What will happen if the buffer is full, will it over-write the stale data with new data.
       b) Handle empty buffer case in dequeue routine.
       c) Add more error codes for failure cases given in point '3.a' and '3.b'.
    4) Add required routines suggested below like IsCurrentBufferEmpty() or getCurrentBufferSize() if needed.
    5) Provide Unit Test.
*/

/*
* This is a circular buffer that allows enqueue or dequeue arbitrary
* amount of bytes. The buffer size is limited to BUF_SIZE.
*/

static char *GetErrorString(int x);

#define BUF_SIZE    4096

typedef struct {
   int write_index;
   int read_index;
   char *buf;
   int size;
   // bool full; You will need this data member to tell if the queue is full or not.
} circular_buf_t;

circular_buf_t buf;


/**
 // Review Comments
 // The following function will be required to get the current number of elements in buffer.
 // You can add your own way of handling this too.

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

*/

/*
* Enqueue (size) bytes from (client_buf) to the local buf
* memory of (client_buf) is allocated by the caller
*/
int enqueue(char *client_buf, int size)
{
    /**
     // Review  Comments
     // Check for NULL pointer to avoid any segmentaion fault.
     // Check if size is 0, return without any further processing
     */
   if (size > BUF_SIZE) {
    /* Review  Comments
       1) Either use error(2) as used in dequeue for "OverFlow" or add another definition in GetErrorString for error(3).
      */
       printf("%s", GetErrorString(3));
       return 3;
   }

   
   int part1 = buf.size - buf.write_index;
   /**
     // Review  Comments
     // This function needs lot of changes and edge case handling.
     // If the size of client data is greater than the buffer max size then you need to adjust the data from write_index to buffer
     // max size and then add the remaining data from buff[0].
     // Also, make sure if user is allowed to overwrite the old data with new one. If not, then return appropriate errors.

     // Please check the following PsuedoCode for better understanding. Also, this code doesn't handle all the edge cases.
     //
     if(size > part1 )  
     {
      memcpy(buf.buf + buf.write_index, client_buf, part1);
      int part2 = size - part1;
      memcpy(buf.buf, client_buf+part1, part2);

     // Handle possible edge cases to adjust the write and read index accordingly.

     // One of the possible scenario explained below,  please add code to handle other cases.
     // If we have maximum buffer BUF_SIZE = 8, read_index = 7 and write_index = 3, and user want to add [1,2,3,4,5]
     // then read_index will also be adjusted to 0 and write_index to 0 also.
      if((getCurrentBufferSize() + size) > buf.size)
      {
          // Adjust read index for oveflow scenario ( read index moving from 6th index to 4th index like 6, 7, 0, 1, 2, 3 when BUF_SIZE =8  ).
      } 
      buf.write_index = part2;
    }
    else
    { 
      printf("\nAdd2\n");
      memcpy(buf.buf + buf.write_index, client_buf, size);

      // Handle possible edge cases to adjust the write and read index.
      // Adjust read index when buffer is full and user is overwriting the old data.
      // Adjust write index for every write to buffer.
    }
   */

   /* Add appropriate comments to clarify the intention for the following lines */
   memcpy(client_buf, buf.buf + buf.write_index, part1);

   if (part1 != size) {
       int part2 = size - part1;
       memcpy(client_buf+part1, buf.buf[0], part2);
   }
   /**
    // Review Comments 
    // Forgot to adjust the write and read index 
    //  Check if local buffer is full using following psuedo-code or provide other implementation to handle the same.
    if(buf.read_index == buf.write_index)
    {
      buf.full = 1;
    }
    */

   return 0;
}

/*
* Dequeue (size) bytes from the local buf to (client_buf),
* (client_buf) is allocated by the caller. It is okay to assume
* (client_buf) is big enough to hold all the (size) bytes
*/
int dequeue(char *client_buf, int size)
{
    /**
     // Review  Comments
     // Check for NULL pointer to avoid any segmentation fault.
     // Check if size is 0, return without any further processing.
     // Handle the case when queue will be empty and return an appropriate error.
     // Check how many elements are available and how much data is requested, if
     // we don't have enough number of elements that user requested return an appropriate 
     // error. 
     */
  // Check following if-condition statement.
   if (size < BUF_SIZE) {
       printf("%s", GetErrorString(2));
       return 2;
   }
  /* Review  Comments
     // Use this following pseudo code
       if(isBufferEmpty())
       {
        // Return "EMPTY BUFFER" - Add similar kind of error
        // in GetErrorString and handle it accordingly.
      }

       int available_size = getCurrentBufferSize();
      if(available_size < size)
      {
        // Return "UNAVAILABLE NUMBER OF REQUESTED BYTES" - Add similar kind of error
        // in GetErrorString and handle it accordingly.
      } 
     // Forgot to adjust the write and read index  
     // Only handling a case where write index is greater than read index.
     // but, there is a possibilty that read index is greater than write index, please handle 
     // the suggested case.
     //
     // Following implementation should be done as given below where read_index is less than write index.
      if(buf.read_index < buf.write_index)
      {
        memcpy(client_buf, buf.buf + buf.read_index, size);
        buf.read_index += size;
      }
      else
      {
         // Add code to handle when write_index is less than read_index.
         int part1 = buf.size - ( buf.read_index);
          if(size <= part1)
          {
            // Handle the case when read index will stay inside the max buffer size limit.
            memcpy(client_buf, buf.buf + buf.read_index, size);
            buf.read_index = (buf.read_index + size)%% buf.size;;

          }
          else
          {
            // Handle the case when read index will cross the max buffer size and start again from index 0.
          }
      }
   */
   int copy_size = buf.write_index - buf.read_index + 1;
   memcpy(client_buf, buf.buf + buf.write_index, copy_size);

  // Make sure to set the full flag to false
  // buf.full = false;
   return 0;
}

static char *GetErrorString(int x)
{
   /* Review
      1) Declare following variable as "static char errorString[20]"
      2) Either increase the errorString size to accomodate "Success -- No error."
         or change the string  to "Success". 
      3) Use object-like MACRO to maintain the size of error string so that
         Example:  #define   MAX_ERROR_STRING_SIZE 20
      4) Add an error to handle if local buffer size is less than the client buffer or
         add meaningful definition for "Overflow".
   */
   char errorString[20];

   switch ( x )
   {
       case 0:
       /* Review Comments
          1) Use following statement to copy the error in errorString
          2) snprintf (errorString, 20, "Success -- No error.");
       */
           errorString = "Success -- No error.";
           break;
       case 2:
       /* Review Comments
          1) Use following statement to copy the error in errorString
          2) snprintf (errorString, 20, "Overflow!");
        */
           errorString = "Overflow!";
           break;
       /* Review Comments
          1) Handle default case to either store "UNKOWN ERROR" or return NULL.
       */
   }
   /* Review Comments
      No need to add null character, it will be added automatically by sprintf
    */
   errorString[19] = 0;
   return errorString;
}


int main(int argc,char* argv[])
{
   // initialize buffer
   buf.buf = malloc(BUF_SIZE);
   buf.size = BUF_SIZE;

   /* Comments
    * Intialize the write and read index to 0.
    * 
    */

   // Perform enqueue() and dequeue();

   // All completed, return

  /* Comments
   * Free allocated buffer to avoid any memory leakage.
   */
   return 0;
}