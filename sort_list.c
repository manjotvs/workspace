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

void add_element(int val)
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
	printf("LINKED LIST ELEMENTS:- ");
	while(ll != NULL)
	{
		printf("%d ", ll->data);
		ll = ll->next;
		num_of_nodes++;
	}
	printf("\n");
}


node_t* find_mid(node_t *itr)
{
	node_t *slow;
	node_t *fast;

	slow = itr;
	fast = itr;
	while(fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


node_t* sort(node_t* itr1, node_t *itr2)
{
	node_t *itr = malloc(sizeof(node_t));
	memset(itr, 0, sizeof(node_t));
	node_t *h = itr;
	while(itr1 != NULL && itr2 != NULL)
	{
		//printf("hi1: %d\n", head->data);
		if(itr1->data < itr2->data)
		{
			itr->next = itr1;
			itr1 = itr1->next;  
		}
		else
		{
			itr->next = itr2;
			itr2 = itr2->next;
		}
		itr = itr->next;
	}

	if(itr1 != NULL)
	{
		itr->next = itr1;
	}
	if(itr2 != NULL)
	{
		itr->next = itr2;
	}
	return h->next;

}

node_t* merge_sort(node_t* itr)
{
	static char i=0;
	if(itr == NULL || itr->next == NULL)
	{
		return itr;
	}
	node_t *itr1;
	node_t *itr2;
	itr1 = itr;
	node_t* mid = find_mid(itr);
	itr2 = mid->next;
	mid->next = NULL;

	//printf("hello: %d %d %d\n", itr->data,i, mid->data);
	printf("Before Sorting\n");
	traversal(itr1);
	traversal(itr2);
	if(i < 30)
	{
		i++;
		itr1 = merge_sort(itr1);
		itr2 = merge_sort(itr2);
		printf("After Sorting\n");
		traversal(itr1);
		traversal(itr2);
	}
	return(sort(itr1, itr2));
	
}

int main()
{
	sp = head;
	add_element(10);
	add_element(2);
	add_element(13);
	add_element(-2);
	add_element(1);
	//printf("List is palindrome(True or False): %d\n",recur_ll(head, &head));
	traversal(head);

//	node_t *mid = find_mid(head, NULL);
//	printf("Middle element is: %d\n", mid->data );
	head = merge_sort(head);
	traversal(head);

	
	return 0;
	

}
