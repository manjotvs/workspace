#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *next;
}node_t;

node_t *head = NULL;
node_t *list_pointer = NULL;

// void *add_node( node_t **p, char val)
// {
// 	node_t *new_node = NULL;
// 	new_node = (node_t*)sizeof(node_t);
// 	new_node->data = val;
// 	if(head == NULL)
// 	{
// 		head = new_node;
// 		p = &new_node;
// 	}
// 	else
// 	{
// 		*p = (*p)->next;
// 		p = &new_node; 
// 	}
// }

void *add_node( char val)
{
	node_t *new_node = NULL;
	new_node = (node_t*)malloc(sizeof(node_t));
	new_node->data = val;
	new_node->next = NULL;
	if(head == NULL)
	{
		list_pointer = head = new_node;
	}
	else
	{
		list_pointer->next = new_node; 
		list_pointer = list_pointer->next;
	}
}

void print_ll()
{
	node_t *itr = head;
	printf("\nLinked List nodes follow as ");
	while(itr != NULL)
	{
		printf("%d ", itr->data );
		itr = itr->next;
	}
	printf("\n");
}


void find_delete_middle()
{
	node_t *slow, *fast, *prev_node;
	slow = head;
	fast = head;
	prev_node = NULL;

	while(fast != NULL && fast->next != NULL)
	{
		prev_node = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("Preious Node before middle element is %d\n", prev_node->data);
	printf("Middle Node is %d\n", slow->data);
	prev_node->next = slow->next;
	free(slow);
}

int main()
{
	add_node(5);
	add_node(10);
	add_node(4);
	add_node(1);
	add_node(9);
	add_node(12);
	add_node(13);
	add_node(15);

	print_ll();

	node_t *middle_node = NULL;
	find_delete_middle();
	printf("Linked list after deleting its middle node!");
	print_ll();
	return 0;
}