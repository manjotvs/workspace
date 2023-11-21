#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// typedef struct queue{
// 	int data;
// 	struct queue *next;
// } MyCircularQueue;
typedef struct queue{
	int data;
	struct queue *next;
} MyCircularQueue;

MyCircularQueue *curr = NULL;
MyCircularQueue *last = NULL;
int counter = 0;
int size;

MyCircularQueue* myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
bool myCircularQueueDeQueue(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) 
{
	size =k;
    MyCircularQueue *queue = NULL;
    MyCircularQueue *node;
    MyCircularQueue *head;
    while(k--)
    {
    	node = malloc(sizeof(MyCircularQueue));
    	node->data = 0;
    	node->next = NULL;
    	if(queue == NULL)
    	{
    		head = queue = node;
    	}
    	else
    	{
    		queue->next = node;
    		queue = queue->next;
    	}
    	node = NULL;
    }
    queue->next = head;
    return head;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
	if(myCircularQueueIsFull(obj))
		return 0;
	if(curr == NULL)
	{
		last = obj;
		curr = obj;
	}
	else
	{
		// while(curr != obj)
		// {
		// 	obj = obj->next;
		// }
		// curr = obj->next;
		curr = curr->next;
	}
	curr->data = value;
	counter++;
	return 1;
}


/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
	if(myCircularQueueIsEmpty(obj))
		return 0;
	//printf("Dequeue:%d & curr data %d counter %d\n",last->data, curr->data, counter );
	last->data = 0;
	if((last == curr) && (counter == 1))
	{
		printf("Dequeue Reset\n");
		last = NULL;
		curr = NULL;
	}
	else
	{
		last = last->next;
	}
	counter --;
	return 1;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
	if(last == NULL)
		return 1;
	return 0;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
	if(counter == (size))
		return 1;
	return 0;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) 
{
	if(myCircularQueueIsEmpty(obj))
		return -1;
	return last->data;
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) 
{
	if(myCircularQueueIsEmpty(obj))
		return -1;
	return curr->data;
}

void myCircularQueueFree(MyCircularQueue* obj) 
{
	MyCircularQueue* itr;
	MyCircularQueue* temp;
	itr = obj->next;
	while(itr != obj )
	{	
		//printf("val1:%d\n",itr->data);
		temp = itr;
		itr = itr->next;
		temp->next = NULL;
		free(temp);
	}
	itr->next = NULL;
	free(itr);
	obj = NULL;
	last = NULL;
	curr = NULL;
    counter = 0;
}



void print(MyCircularQueue* obj)
{
	MyCircularQueue* itr;
	itr = obj;
	while(itr->next != obj )
	{
		printf("val:%d\n",itr->data);
		itr = itr->next;
	}
	printf("val:%d\n",itr->data);
}


int main()
{
	MyCircularQueue *queue;

	//["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]
	//[[3],[1],[2],[3],[4],[],[],[],[4],[]]
	queue = myCircularQueueCreate(3);
	printf("Enqueue: %d\n", myCircularQueueEnQueue(queue, 1));
	printf("Enqueue: %d\n", myCircularQueueEnQueue(queue, 2));
	printf("Enqueue: %d\n", myCircularQueueEnQueue(queue, 3));
	printf("Enqueue: %d\n", myCircularQueueEnQueue(queue, 4));
	printf("Current: %d\n", myCircularQueueRear(queue));
	printf("Full: %d\n", myCircularQueueIsFull(queue));
	printf("Dequeue: %d\n", myCircularQueueDeQueue(queue));
	myCircularQueueEnQueue(queue, 4);
	printf("Current: %d\n", myCircularQueueRear(queue));
	printf("Prev: %d\n", myCircularQueueFront(queue));
	myCircularQueueFree(queue);
	printf("Queue after freeing\n");
	//printf("Current: %d\n", myCircularQueueRear(queue));
	//printf("Prev: %d\n", myCircularQueueFront(queue));
	//print(queue);

	//["MyCircularQueue","enQueue","Rear","Rear","deQueue","enQueue","Rear","deQueue","Front","deQueue","deQueue","deQueue"]
	//[[6],[6],[],[],[],[5],[],[],[],[],[],[]]
	// printf("New Queue\n\n\n");
	// queue = myCircularQueueCreate(6);
	// myCircularQueueEnQueue(queue, 6);

	
	// printf("Current: %d\n", myCircularQueueRear(queue));
	// printf("Current: %d\n", myCircularQueueRear(queue));
	// printf("Dequeue: %d\n", myCircularQueueDeQueue(queue));
	// myCircularQueueEnQueue(queue, 5);
	// printf("Queue after enqueue\n");
	// print(queue);
	// printf("Current: %d\n", myCircularQueueRear(queue));
	// printf("Dequeue: %d\n", myCircularQueueDeQueue(queue));
	// printf("Prev: %d\n", myCircularQueueFront(queue));
	// printf("Dequeue: %d\n", myCircularQueueDeQueue(queue));
	// printf("Dequeue: %d\n", myCircularQueueDeQueue(queue));
	// printf("Dequeue: %d\n", myCircularQueueDeQueue(queue));
	// myCircularQueueFree(queue);
	// printf("Queue after freeing\n");

	// //["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","deQueue","deQueue","isEmpty","isEmpty","Rear","Rear","deQueue"]
	// //[[8],[3],[9],[5],[0],[],[],[],[],[],[],[]]

	// printf("New Queue\n\n\n");
	// queue = myCircularQueueCreate(8);
	// myCircularQueueEnQueue(queue, 3);
	// myCircularQueueEnQueue(queue, 9);
	// myCircularQueueEnQueue(queue, 5);
	// myCircularQueueEnQueue(queue, 0);
	// printf("Dequeue: %d\n", myCircularQueueDeQueue(queue));
	// printf("Dequeue: %d\n", myCircularQueueDeQueue(queue));
	// printf("Empty: %d\n", myCircularQueueIsEmpty(queue));
	// printf("Empty: %d\n", myCircularQueueIsEmpty(queue));
	// printf("Current: %d\n", myCircularQueueRear(queue));
	// printf("Current: %d\n", myCircularQueueRear(queue));
	// printf("Dequeue: %d\n", myCircularQueueDeQueue(queue));
	return 0;


}