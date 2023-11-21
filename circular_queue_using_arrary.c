#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int front;
    int rear;
    int counter;
    int limit;
    int *arr;
} MyCircularQueue;


/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->counter)
        return 0;
    return 1; 
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(obj->counter < obj->limit )
		return 0;
	return 1;
}

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj;
    
	obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->limit = k;
    obj->front = 0;
    obj->rear = -1;
    obj->counter = 0;
	obj->arr = (int*)malloc(sizeof(int)*obj->limit);
    return obj;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  	if(myCircularQueueIsFull(obj))
        return 0;

    obj->rear = (obj->rear + 1) % obj->limit;
    obj->arr[obj->rear] = value;
    obj->counter++;
    return 1;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    bool ret = 0;
	if(!myCircularQueueIsEmpty(obj))
	{
		ret = 1;
		obj->arr[obj->front];
		obj->front = (obj->front+1) % obj->limit;
		obj->counter--;
	}
	return ret;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if(!myCircularQueueIsEmpty(obj))
    	return obj->arr[obj->front];
    return -1;
  
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if(!myCircularQueueIsEmpty(obj))
    	return obj->arr[obj->rear];
    return -1;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    obj->arr = NULL;
    free(obj);
    obj = NULL;
}


// Function displaying the elements 
// of Circular Queue 
void displayQueue(MyCircularQueue* obj) 
{ 
	int temp = obj->counter;
	int i = obj->front;
	printf("Queue Elements:");
	while(temp)
	{
		printf(" %d", obj->arr[(i++)%(obj->limit)]);
		temp--;
	}
	printf("\n");
} 

/* Driver of the program */
int main() 
{ 
// 	[["MyCircularQueue","enQueue","deQueue","Front","deQueue","Front","Rear","enQueue","isFull","deQueue","Rear","enQueue"]
//[[3],[7],[],[],[],[],[],[0],[],[],[],[3]]
	//[null,true,6,6,true,true,5,true,-1,false,false,false]
	MyCircularQueue *obj;
	obj = myCircularQueueCreate(3);
	printf("%d\n",obj->limit );
	// // Inserting elements in Circular Queue 
	printf("Enqueue: %d\n", myCircularQueueEnQueue(obj, 7)); 
	printf("Dequeue: %d\n",myCircularQueueDeQueue(obj));
	printf("Front: %d\n", myCircularQueueFront(obj));
	printf("Dequeue: %d\n",myCircularQueueDeQueue(obj));
	printf("Front: %d\n", myCircularQueueFront(obj));

	printf("Rear: %d\n", myCircularQueueRear(obj));
	printf("Enqueue: %d\n", myCircularQueueEnQueue(obj, 0)); 
	printf("Full: %d\n",myCircularQueueIsFull(obj));
	printf("Dequeue: %d\n",myCircularQueueDeQueue(obj));
	printf("Rear: %d\n", myCircularQueueRear(obj));
	printf("Enqueue: %d\n", myCircularQueueEnQueue(obj, 3));
	// printf("Dequeue: %d\n",myCircularQueueDeQueue(obj));
	// printf("Dequeue: %d\n",myCircularQueueDeQueue(obj));

	// printf("Rear: %d\n", myCircularQueueRear(obj));
	// myCircularQueueEnQueue(obj, 13); 
	// myCircularQueueEnQueue(obj, -6); 
	// myCircularQueueEnQueue(obj, -45);
	// myCircularQueueEnQueue(obj, -55);  

	// printf("Rear: %d\n", myCircularQueueRear(obj));

	// // Display elements present in Circular Queue 
	displayQueue(obj); 

	// // Deleting elements from Circular Queue 
	// printf("Deleted value = %d\n", deQueue()); 
	// printf("Deleted value = %d\n", deQueue()); 

	// displayQueue(); 

	// myCircularQueueEnQueue(obj, 9); 
	// myCircularQueueEnQueue(obj, 20); 
	// myCircularQueueEnQueue(obj, 5); 
	// myCircularQueueEnQueue(obj, 6);
	// deQueue();
	// myCircularQueueEnQueue(obj, 7);

	// displayQueue(); 

	// myCircularQueueEnQueue(obj, 20); 
	// printf("Deleted value = %d\n", deQueue()); 
	// printf("Deleted value = %d\n", deQueue()); 
	// printf("Deleted value = %d\n", deQueue()); 
	// printf("Deleted value = %d\n", deQueue()); 
	// printf("Deleted value = %d\n", deQueue()); 
	// printf("Deleted value = %d\n", deQueue()); 
	// printf("Deleted value = %d\n", deQueue()); 
	// printf("Deleted value = %d\n", deQueue()); 
	// printf("Deleted value = %d\n", deQueue()); 
	// printf("Deleted value = %d\n", deQueue()); 
	// printf("Deleted value = %d\n", deQueue()); 
	return 0; 
} 
