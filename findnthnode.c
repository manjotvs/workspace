#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char find_nth_node(node_t *itr, char n)
{
	static int i = 0;
	char data=0;
	// if(i > num_of_nodes)
	// 	return (n - num_of_nodes);
	if(itr == NULL)
		return 0;
		
	data = find_nth_node(itr->next, n);

	//printf("itr_data1(%d) %d\n",i, itr->data);

	i++;
	if(i == n)
	{
		printf("itr_data2(%d, %d) %d\n",i,n, itr->data);
		return itr->data;
	}
	return data;

}

void reverse(node_t** head_ref) 
{ 
    node_t *prev   = NULL; 
    node_t *current = *head_ref; 
    node_t *next= NULL; 
    while (current != NULL) 
    { 
        next  = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
}


int main()
{
	sp = head;
	uint8_t nth = 6;
	add_element(23);
	add_element(53);
	add_element(33);
	add_element(34);
	add_element(38);
	add_element(78);
	add_element(12);
	add_element(7);
	add_element(105);
	add_element(47);
	//sp->next = head;
	//add_element(78);
	char temp;
	traversal(head);
	temp = find_nth_node(head, nth);
	printf("temp: %d\n", temp );
	reverse(&head);
	traversal(head);

	return 0;
	

}
