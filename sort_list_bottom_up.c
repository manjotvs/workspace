#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node{
	int data;
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

// K will be even always so I can move my pointer two times everytime
node_t* find_k_elements(node_t *itr, char k)
{
	//if(itr!= NULL)
	//	return itr;
	char i=1;
	node_t *second;
	//itr = itr;
	//printf("hello\n");
	while(itr !=NULL && i < k)
	{
		//printf("%d\n", itr->data );
		itr= itr->next;
		i+=1;
	}
	if(!itr) return itr;
	second = itr->next;
	itr->next = NULL;
	//printf("hi\n");
	return second;
}


node_t* sort(node_t* itr1, node_t *itr2, node_t *itr)
{
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

	while(itr->next != NULL)
	{
		itr = itr->next;
	}
	//itr->next = NULL;
	//traversal(h);
	return itr;
}

node_t* merge_sort(node_t* head, char size)
{
	char i = 0, j=0;
	node_t *itr;
	node_t* p1;
	node_t* p2;
	node_t temp;
	node_t *temp1;
	node_t *temp2;
	temp.next = head;
	
	for(i = 1; i < size; i=i<<1 )
	{
		itr = temp.next;
		temp1 = &temp; 
		for(j = 0; itr; j++)
		{
			p1 = itr;
			p2 = find_k_elements(p1, i);
			itr = find_k_elements(p2, i);
			temp1 = sort(p1,p2,temp1);
		}
	}
	return temp.next;
}

int main()
{
	sp = head;
	add_element(10);
    add_element(2);
	add_element(13);
	add_element(-1);
	add_element(19);
	add_element(-11);
	add_element(222);
	add_element(-2);
	add_element(22);
	//printf("List is palindrome(True or False): %d\n",recur_ll(head, &head));
	traversal(head);
	//node_t *mid = find_k_elements(head->next, 1);
	//printf("Middle element is: %d\n", mid->data );
	head = merge_sort(head, 9);
	traversal(head);

	
	return 0;
	

}
