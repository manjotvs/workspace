#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//#define DEBUG
#define OVERFLOW_ENABLE

/* Implement circular buffer using array */
typedef struct 
{
	uint8_t head;
	uint8_t tail;
	uint8_t total_size;
    uint8_t curr_size;
    char *cbuf;
}cirBuf_t;

bool isBufEmpty(cirBuf_t* buf)
{
	return (buf->curr_size == 0);
}

bool isBufFULL(cirBuf_t* buf)
{
	#ifdef DEBUG
	printf("Current Size: %d\n", buf->curr_size);
	#endif
	return (buf->curr_size == buf->total_size);
}

// 1 - Error or 0 - Success
// No Overflow
bool enqueue(cirBuf_t* buf, int n)
{
	if(isBufFULL(buf))
	{
		#ifdef OVERFLOW_ENABLE
			buf->tail = (buf->tail + 1) %buf->total_size;
		#else
			printf("Buffer is Full\n");
			return 1;
		#endif
	}
	else
	{
		buf->curr_size = (buf->curr_size + 1);
	}

	buf->cbuf[buf->head] = n;
	buf->head = (buf->head + 1) % buf->total_size;
	
	return 0;
}

// 1 - Error or 0 - Success
bool dequeue(cirBuf_t* buf, int *n)
{
	if(isBufEmpty(buf))
	{
		printf("Buffer is Empty\n");
		return 1;
	}

	*n = buf->cbuf[buf->tail];
	buf->tail = (buf->tail + 1) %buf->total_size;
	buf->curr_size--;
	return 0;
}

cirBuf_t* circularBufferInit(uint8_t n)
{
	if(n == 0)
	{
		return NULL;
	}
	cirBuf_t *cir_buf = (cirBuf_t*)malloc(sizeof(cirBuf_t));
    cir_buf->head = 0;
    cir_buf->tail = 0;
    cir_buf->curr_size = 0;
    cir_buf->total_size = n;
    cir_buf->cbuf = (char*)malloc(sizeof(char)*n);
    return cir_buf;
}

void display(cirBuf_t* buf)
{
	uint8_t i = 0;
    uint8_t j = buf->tail;
    printf("Head: %d\n",buf->head );
    printf("Tail: %d\n",buf->tail );
    printf("Current Elements in buffer(%d):",buf->curr_size);
	while(i++ < buf->curr_size)
	{
		printf(" %d", buf->cbuf[j]);
		j = (j +1)%buf->total_size;
	}
	printf("\n");
}

int main()
{
	uint8_t num = 5;
    int ret= -10000;
    cirBuf_t *buf = circularBufferInit(num);
    
    printf("enq: %d %d\n", enqueue(buf, -2), buf->curr_size ); 

    // if(!dequeue(buf, &ret))
    // 	printf("Popped Element: %d\n", ret);
    // if(!dequeue(buf, &ret))
    // 	printf("Popped Element: %d\n", ret);
    printf("enq: %d %d\n", enqueue(buf, -3), buf->curr_size ); 
    enqueue(buf, -4);
    enqueue(buf, -5);
    enqueue(buf, -6);
    enqueue(buf, -7);
    enqueue(buf, -8);
    enqueue(buf, -9);
    if(!dequeue(buf, &ret))
    	printf("Popped Element: %d\n", ret);
    if(!dequeue(buf, &ret))
    	printf("Popped Element: %d\n", ret);
    if(!dequeue(buf, &ret))
    	printf("Popped Element: %d\n", ret);
    if(!dequeue(buf, &ret))
    	printf("Popped Element: %d\n", ret);
    if(!dequeue(buf, &ret))
    	printf("Popped Element: %d\n", ret);
    if(!dequeue(buf, &ret))
    	printf("Popped Element: %d\n", ret);
    if(!dequeue(buf, &ret))
    	printf("Popped Element: %d\n", ret);
    if(!dequeue(buf, &ret))
    	printf("Popped Element: %d\n", ret);
    if(!dequeue(buf, &ret))
    	printf("Popped Element: %d\n", ret);
    
    display(buf);

	return 0;
}