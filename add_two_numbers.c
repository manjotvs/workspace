#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	char val;
	struct node* next;
}ListNode1;

ListNode1* create_new_node(char val)
{
	ListNode1* node;
	node = malloc(sizeof(ListNode1));
	node->val = val;
	node->next = NULL;
	return node;
}

void create_ll_number(ListNode1 **num, char digit)
{
	ListNode1 *new_node = create_new_node(digit);
	if( *num == NULL )
	{
		*num = new_node;
	}
	else
	{
		ListNode1 *head = *num;
		while(head->next != NULL)
		{
			head = head->next;
		}
		head->next = new_node;
	}
}

void display_number(ListNode1 *N)
{
	printf("Given Number: ");
	while(N != NULL)
	{
		printf("%d ", N->val );
		N = N->next;
	}
	printf("\n");
}


ListNode1* add_two_number( ListNode1* N1, ListNode1* N2)
{
	char sum = 0, carry = 0;
	ListNode1 *N3 = NULL; 

	while(( N1!= NULL ) && ( N2!= NULL ))
	{
		sum = carry + N1->val + N2->val;
		printf("Sum: %d\n", sum );
		carry = sum /10;
		sum = sum%10;
		create_ll_number(&N3, sum);
		N1 = N1->next;
		N2 = N2->next;
	}

	while( N1 != NULL)
	{
		sum = carry + N1->val;
		carry = sum /10;
		sum = sum %10;
		create_ll_number(&N3, sum);
		N1 = N1->next;
	}
	while( N2 != NULL)
	{
		sum = carry + N2->val;
		carry = sum /10;
		sum = sum %10;
		create_ll_number(&N3, sum);
		N2 = N2->next;
	}
	if(carry)
	{
		create_ll_number(&N3, carry);
	}
	return N3;
}

int main()
{
	ListNode1 *N1 = NULL;
	ListNode1 *N2 = NULL;
	ListNode1 *sum = NULL;
	create_ll_number(&N1, 7);
	create_ll_number(&N1, 4);
	create_ll_number(&N1, 3);
	create_ll_number(&N2, 3);
	create_ll_number(&N2, 7);
	create_ll_number(&N2, 9);
	create_ll_number(&N2, 9);
	//create_ll_number(&N2, 9);
	//create_ll_number(&N2, 9);


	display_number(N1);
	display_number(N2);

	sum = add_two_number(N1, N2);
    display_number(sum);
	return 0;
}