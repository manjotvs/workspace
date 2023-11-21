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

void find_middle_element()
{
	node_t *slow, *fast;
	slow = fast = head;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("Middle Element is %d\n", slow->data );
}

uint8_t find_loop()
{
	node_t *slow, *fast, *prev_node;
	slow = fast = head;
	//char i = num_of_nodes;
	while(fast->next!= NULL && fast != NULL)
	{
		prev_node = slow;
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)
		{
			printf("Loop starts from %d\n", slow->data );
			printf("Loop starts from %d\n", prev_node->data );
			prev_node->next = NULL;
			return 1;
		}
		//i--;
	} 
	return 0;
}


int main()
{
	sp = head;

	add_element(23);
	add_element(53);
	add_element(33);
	add_element(34);
	add_element(38);
    sp->next = head;
    add_element(39);
	//sp->next = head;
	//add_element(78);
	//traversal(head);
	//find_middle_element();
	printf("Loop detected %d\n", find_loop());
	traversal(head);

}
