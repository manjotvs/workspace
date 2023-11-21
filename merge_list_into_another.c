// C program to merge a linked list into another at 
// alternate positions 
#include <stdio.h> 
#include <stdlib.h> 

// A nexted list node 
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

/* Function to insert a node at the beginning */
void push(struct Node ** head_ref, int new_data) 
{ 
	struct Node* new_node = 
		(struct Node*) malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Utility function to print a singly linked list */
void printList(struct Node *head) 
{ 
	struct Node *temp = head; 
	while (temp != NULL) 
	{ 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
	printf("\n"); 
} 

// Main function that inserts nodes of linked list q into p at 
// alternate positions. Since head of first list never changes 
// and head of second list may change, we need single pointer 
// for first list and double pointer for second list. 
void merge(struct Node *p, struct Node **q) 
{ 
	struct Node *itr1;
	struct Node *itr2;
	struct Node *temp1;
	struct Node *temp2;

	itr1 = p;
	itr2 = *q;

	while( itr1!= NULL & itr2 != NULL)
	{
		printf("itr1 & itr2: %d %d\n", itr1->data, itr2->data);
		temp1 = itr1->next;
		temp2 = itr2->next;
		itr2->next = temp1;
		itr1->next = itr2;
		//itr2= NULL;
		//free(itr2);
		// if(itr1->next->next == NULL)
		// {
		// 	itr1 = itr1->next;
		// 	break;
		// }
		itr1 = temp1;

		itr2 = temp2;
	}
	// while(itr2!= NULL)
	// {
	// 	printf("itr2 & itr1: %d %d\n",itr2->data, itr1->data);
	// 	itr1->next = itr2;
	// 	itr2 =itr2->next;
	// 	itr1 = itr1->next;
	// }
	*q = itr2;

} 

// Driver program to test above functions 
int main() 
{ 
	struct Node *p = NULL, *q = NULL; 
	push(&p, 3); 
	push(&p, 2); 
	push(&p, 1); 
	printf("First Linked List:\n"); 
	printList(p); 

	push(&q, 8); 
	push(&q, 7); 
	push(&q, 6); 
	push(&q, 5); 
	push(&q, 4); 
	printf("Second Linked List:\n"); 
	printList(q); 

	merge(p, &q); 

	printf("Modified First Linked List:\n"); 
	printList(p); 

	printf("Modified Second Linked List:\n"); 
	printList(q); 

	//getchar(); 
	return 0; 
} 

