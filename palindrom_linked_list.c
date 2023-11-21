#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node{
	char data;
	struct node *next;
}node_t;

node_t *sp;
node_t *head = NULL;
char num_of_nodes=0;

void add_element(char val)
{
	node_t *temp;
	if(head == NULL)
	{
		head = malloc(sizeof(node_t));
		memset(head, 0, sizeof(node_t));
		head->data = val;
		head->next = NULL;
		sp = head;
	}
	else
	{
		temp = malloc(sizeof(node_t));
		memset(temp, 0, sizeof(node_t));
		temp->data = val;
		temp->next = NULL;
		sp->next = temp;	
		sp = sp->next;
	}
}

void traversal(node_t *ll)
{
	printf("LINKED LIST ELEMENTS:- \n");
while(ll != NULL)
	{
		printf("%d\n", ll->data);
		ll = ll->next;
		num_of_nodes++;
	}
}

bool recur_ll(node_t *itr1, node_t **itr2)
{
	bool temp;
	if(itr1 == NULL)
	{
		return true; 
	}
	temp = recur_ll(itr1->next, itr2);
	if(temp == false)
		return false;
	printf("Nodes Value %d %d\n", itr1->data, (*itr2)->data );
	if((*itr2)->data == itr1->data)
	{
		*itr2 = (*itr2)->next;
		return true;
	}
	else
		return false;
	
}


bool isPalindrome(node_t *itr)
{
	node_t *slowPtr, *fastPtr;
	node_t *prevPtr = NULL;
	node_t *nextPtr = NULL;

	slowPtr = fastPtr = itr;
	while(fastPtr!= NULL && fastPtr->next != NULL )
	{
		//printf("FAST: %d\n",fastPtr->data );
		fastPtr = fastPtr->next->next;
		nextPtr = slowPtr->next;
		slowPtr->next = prevPtr;
		prevPtr = slowPtr;
		slowPtr = nextPtr;
	}
	// Fastptr will be NULL if there are even number of elements in linked lists
	// and vice-versa.
	if(fastPtr != NULL)
	{
		slowPtr = slowPtr->next;
	}
	
	while(prevPtr!= NULL)
	{
		printf("Middle Element is %d %d\n", prevPtr->data, slowPtr->data);
		if(prevPtr->data != slowPtr->data)
			return false;
		prevPtr = prevPtr->next;
		slowPtr = slowPtr->next;
	}
	return true;


}


int main()
{
	sp = head;
	add_element(1);
	add_element(2);
	add_element(3);
	add_element(2);
	add_element(1);
	//printf("List is palindrome(True or False): %d\n",recur_ll(head, &head));
	//traversal(head);
	printf("List is palindrome(True or False): %d\n", isPalindrome(head));

	return 0;
	

}
