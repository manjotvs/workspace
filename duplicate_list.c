#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	char data;
	struct node *next_node;
}node_t;


char push(node_t **n, char val)
{
	if(*n == NULL)
	{
		node_t *new_node;
		new_node = malloc(sizeof(node_t));
		memset(n, 0, sizeof(node_t));
		new_node->data = val;
		new_node->next_node =NULL;
		*n= new_node;

		return 0;
	}
	node_t *temp;
	temp = *n;
	while(temp->next_node != NULL)
	{
		temp = temp->next_node;
	}
	node_t *new_node;
	new_node = malloc(sizeof(node_t));
	memset(new_node, 0, sizeof(node_t));
	new_node->data = val;
	temp->next_node = new_node;
	return 0;
}


char delete_duplicate_node(node_t **n)
{
	if(*n == NULL)
		return -1;
	node_t *next1_node;
	node_t *curr_node;
	node_t *temp;
	curr_node = *n;
	while(curr_node->next_node != NULL)
	{
		if(curr_node->data == curr_node->next_node->data)
		{
			if(curr_node->next_node->next_node != NULL)
				next1_node = curr_node->next_node->next_node;
			else
				next1_node = NULL;
			temp = curr_node->next_node;
			free(temp);
			curr_node->next_node = next1_node;
		}
		else
		{
			curr_node = curr_node->next_node;
		}
	}
	return 0;
}

int main()
{
	node_t *a=NULL;
	node_t *head;
	push(&a,1);
	push(&a,1);
	push(&a,1);
	push(&a,1);
	push(&a,1);
	push(&a,1);
	push(&a,4);
	push(&a,4);
	push(&a,4);
	push(&a,4);
	push(&a,4);
	push(&a,4);
	push(&a,10);
	push(&a,10);
	push(&a,10);
	push(&a,10);
	push(&a,10);
	push(&a,10);
	push(&a,10);
	push(&a,10);
	push(&a,10);
	push(&a,10);
	push(&a,12);

	push(&a,12);

	push(&a,12);

	push(&a,12);
	push(&a,12);
	head = a;
	printf("List with duplicates nodes: ");
	while(head)
	{
		printf("%d, ", head->data );
		head = head->next_node;
	}

	delete_duplicate_node(&a);
	printf("\nList after removing duplicates node: ");
	head = a;
	while(head)
	{
		printf("%d, ", head->data );
		head = head->next_node;
	}
	printf("\n");
	return 0;
}