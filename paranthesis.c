#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct node{
	char data;
	struct node* next_node;
}node_t;

node_t *stack;

void delete(node_t* head)
{
	if(head->next_node == NULL)
	{
		//printf("Freed a head\n");
		free(head);
		stack = NULL;
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

char push(node_t *head, char value)
{
	if(value == '\0')
	{
		printf("Data is not valid!!!\n");
		return 0;
	}
	if(head == NULL)
	{
		head = (node_t*) malloc(sizeof(node_t));
		memset(head, 0, sizeof(node_t));
		head->data = value;
		stack = head;
		return 1;
	}
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

char pop(node_t *head)
{
	char temp;
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
	delete(head);
	return temp;
}

char close_prths[] = {']','}',')'};
char open_prths[] = {'[','{','('};

char find_open_prths(char c)
{
	for(int i=0; i<3; i++)
	{
		if(c == open_prths[i])
			return c;
	}
	return 0;
}
char find_close_prths(char c)
{
	for(int i=0; i<3; i++)
	{
		if(c == close_prths[i])
			return c;
	}
	return 0;
}
char match(char c)
{
	switch(c)
	{
		case '{':
			return '}';
		case '[':
			return ']';
		case '(':
			return ')';	
		default:
			return 0;	
	}
}
int main()
{
	char str[] = "[]{}()()biucbaiub9090$()";
	char nop=0;
	int i =0;
	while(str[i] !='\0')
	{
		if(find_open_prths(str[i]))
		{
			push(stack, str[i]);
			nop++;
		}
		else if(find_close_prths(str[i]))
		{
			if(match(pop(stack)) == str[i])
				nop--;
			else
				nop++;
		}
		i++;
	}
	if(nop)
	{
		printf("False\n");
	}
	else
		printf("True\n");
	return 0;
}