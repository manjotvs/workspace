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

void reverse_linked_list(node_t *itr)
{
	node_t *curr_node = NULL;
	node_t *prev_node = NULL;
	node_t *next_node = NULL;

	curr_node = itr;
	while(curr_node != NULL)
	{
		next_node = curr_node->next;
		curr_node->next = prev_node;
		prev_node = curr_node;
		curr_node = next_node;
	}
	head = prev_node;
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
	//traversal(head);
	reverse_linked_list(head);
	traversal(head);

	return 0;
	

}
