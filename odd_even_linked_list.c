// C program to arrange a linked list in odd-even fashion. 

#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

void rearrange(struct Node *itr) 
{ 
	if(itr == NULL || itr->next == NULL)
		return;

	struct Node *odd = NULL;
	struct Node *even = NULL;
	struct Node *temp = NULL;

	struct Node *even_s = NULL;
	char i = 1;

	odd = itr;
	even_s = even = odd->next; 
	//itr = even->next;
	printf("Hello\n");
	char k =0;
	while( even != NULL && even->next != NULL && k <5)
	{
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
		k++;
	}
	// if(even != NULL)
	// {
	// 	odd->next = even;
	// 	even->next = even->next;
	// }
	// else
	// {
	// 	even->next = even;
	// }
	odd->next = even_s;
} 

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push (struct Node** head_ref, int new_data) 
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
	
	rearrange(head);

	printf("\nMoved Linked list \n"); 
	printList(head); 
	printf("\n");

	return (0); 
} 

