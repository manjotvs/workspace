// C program to delete N nodes after M nodes of a linked list 
#include <stdio.h> 
#include <stdlib.h> 

// A linked list node 
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

/* Function to insert a node at the beginning */
void push(struct Node ** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print linked list */
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

// Function to skip M nodes and then delete N nodes of the linked list. 
void skipMdeleteN(struct Node *itr, int M, int N) 
{ 
	int i = 1;
	struct Node *temp = NULL;
	struct Node *temp2 = NULL;
	while(itr!= NULL)
	{
		while(itr!= NULL && i < M)
		{
			itr = itr->next;
			i++;
		}
		if(itr == NULL)
			return;
		i = 1;
		temp2 = itr->next;
		while(temp2 != NULL && i <= N)
		{
			temp = temp2;
			temp2 = temp2->next;
			free(temp);
			i++;
		}
		itr->next = temp2;
		itr = temp2;
	}
} 

// Driver program to test above functions 
int main() 
{ 
	/* Create following linked list 
	1->2->3->4->5->6->7->8->9->10 */
	struct Node* head = NULL; 
	int M=2, N=3; 
	push(&head, 10); 
	push(&head, 9); 
	push(&head, 8); 
	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 

	printf("M = %d, N = %d \nGiven Linked list is :\n", M, N); 
	printList(head); 

	skipMdeleteN(head, M, N); 

	printf("\nLinked list after deletion is :\n"); 
	printList(head); 

	return 0; 
} 

