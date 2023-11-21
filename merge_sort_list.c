#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node *next_node;
}node_t;

node_t list;

void delete(node_t **node)
{
	node_t *head;
	head = *node;
	if(head->next_node == NULL)
	{
		//printf("Freed a head\n");
		free(head);
		*node = NULL;
	}
	else
	{
		node_t *tmp;
		node_t *prev;
		tmp = head;
		while(tmp->next_node != NULL)
		{
			prev = tmp;
			tmp = tmp->next_node;
		}
		free(tmp);
		prev->next_node = NULL;
	}
}

char push(node_t **node, char value)
{
	//printf("pushing%ld!!!\n",node);
	if(value == '\0')
	{
		printf("Data is not valid!!!\n");
		return 0;
	}
	if(*node == NULL)
	{
		//printf("Creating a list!!!\n");
		node_t *new_node;
		new_node = (node_t*) malloc(sizeof(node_t));
		memset(new_node, 0, sizeof(node_t));
		new_node->data = value;
		*node = new_node;
		return 1;
	}
	
	node_t *head;
	head = *node;
	node_t *tmp;
	tmp = head;
	while(tmp->next_node != NULL)
	{
		tmp = tmp->next_node;
	}
	node_t *new_node = (node_t*)malloc(sizeof(new_node));
	memset(new_node, 0, sizeof(node_t));
	new_node->data = value;
	tmp->next_node = new_node;
	return 1;
}

char pop(node_t **node)
{
	node_t *head;
	char temp;
	head = *node;
	if(head == NULL)
	{
		//printf("Stack is empty\n");
		return 0;
	}
	node_t *tmp;
	tmp = head;
	while(tmp->next_node != NULL)
	{
		tmp = tmp->next_node;
	}
	temp = tmp->data;
	//printf("Deleting an element %c\n",temp);
	delete(node);
	return temp;
}

node_t* merge_lists_1(node_t *a, node_t *b)
{
	node_t *merge_node = NULL;
	while(a != NULL && b!= NULL)
	{
		if(a->data <= b->data)
		{
			//printf("Push %d!!!\n", a->data);
			push(&merge_node,a->data);
			a = a->next_node? a->next_node : NULL;
		}
		else
		{
			//printf("Push %d!!!\n", b->data);
			push(&merge_node,b->data);
			b = b->next_node? b->next_node : NULL;
		}
	}
	while(a != NULL)
	{
		push(&merge_node, a->data);
		a = a->next_node? a->next_node : NULL;
	}
	while(b != NULL)
	{
		push(&merge_node, b->data);
		b = b->next_node? b->next_node : NULL;
	}

	return merge_node;
}

node_t* merge_lists_2(node_t *a, node_t *b)
{
	if(a == NULL)
	{
		return b;
	}
	if(b == NULL)
	{
		return a;
	}
	node_t *merge_node = NULL;
	node_t *last_node = NULL;
	while(a != NULL && b!= NULL)
	{

		if(merge_node == NULL)
		{
			merge_node = (node_t*) malloc(sizeof(node_t));
			memset(merge_node,0,sizeof(node_t));
			last_node = merge_node;
		}
		else
		{
			node_t * new_node;
			new_node = (node_t*) malloc(sizeof(node_t));
			memset(new_node,0,sizeof(node_t));	
			last_node = last_node->next_node = new_node;
		}
		if(a->data <= b->data)
		{
			//printf("Push %d!!!\n", a->data);
			last_node->data = a->data;
			a = a->next_node? a->next_node : NULL;
		}
		else
		{
			//printf("Push %d!!!\n", b->data);
			last_node->data = b->data;
			b = b->next_node? b->next_node : NULL;
		}
	}
	if(a != NULL)
	{
		last_node->next_node = a;
	}
	if(b != NULL)
	{
		last_node->next_node = b;
	}

	return merge_node;
}

int main()
{
	node_t *a = NULL;
	node_t *b = NULL;
	node_t *merge_list;
	char temp;
	push(&a,1);
	push(&a,3);
	push(&a,5);
	push(&b,1);
	push(&b,2);
	push(&b,4);
	// while((temp=pop(&a)))
	// {
	// 	printf("%d\n",temp);
	// }
	merge_list = merge_lists_2(a,b);
	while((temp=pop(&merge_list)))
	{
		printf("%d\n",temp);
	}
	return 0;
}