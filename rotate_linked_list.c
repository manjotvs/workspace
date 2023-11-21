// C program to rotate a linked list counter clock wise 

#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

// This function rotates a linked list counter-clockwise and 
// updates the head. The function assumes that k is smaller 
// than size of linked list. It doesn't modify the list if 
// k is greater than or equal to size 
void rotate(struct Node **head_ref, int k) 
{ 
	if(k < 1)
		return;

	struct Node *itr;
	struct Node *temp;
	itr = *head_ref;
	char i = 1;

	while( i < k )
	{
		if(itr->next == NULL)
			itr = (*head_ref);
		itr = itr->next;
		i ++;
	}
	temp = itr;
	while(itr->next != NULL)
	{
		itr = itr->next;
	}
	//printf("Last Node: %d\n", itr->data);
	itr->next = *head_ref;
	*head_ref = temp->next;
	
	temp->next = NULL;


	//printf("current node: %d\n", temp->data );
} 

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push (struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = 
		(struct Node*) malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print linked list */
void printList(struct Node *node) 
{ 
	while (node != NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	} 
} 

/* Drier program to test above function*/
int main(void) 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 

	// create a list 10->20->30->40->50->60 
	for (int i = 60; i > 0; i -= 10) 
		push(&head, i); 

	printf("Given linked list \n"); 
	printList(head); 
	rotate(&head, 12); 

	printf("\nRotated Linked list \n"); 
	printList(head); 
	printf("\n");

	return (0); 
} 

