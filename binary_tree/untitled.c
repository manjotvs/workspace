#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX(a,b) ((a>=b)?a:b)

typedef struct tree{
	char data;
	struct tree *right_node;
	struct tree *left_node;
}tree_t;


tree_t* create_new_node(char data)
{
	tree_t* new_node = NULL;
	new_node = (tree_t*) malloc(sizeof(tree_t));
	new_node->left_node = NULL;
	new_node->right_node = NULL;
	new_node->data = data
	return new_node;
}

char pre_order_traversal(tree_t *itr)
{
	static char i=0;
	if(itr!= NULL)
	{
		//i++;		
		printf(" %d", itr->data );
		pre_order_traversal(itr->left_node);
		pre_order_traversal(itr->right_node);
		i++;
	}
	return i;
}
void insert(tree_t **root_node, char val)
{
	tree_t *itr;
	itr = *new_node; 
	if(itr == NULL)
	{
		itr = create_new_node(val);
		root_node = *itr;
		return;
	}
	while(itr != NULL)
	{
		if(val > itr->data)
			itr = itr->right_node;
		else
			itr = itr->left_node;
	}
	itr = create_new_node(val);
}

int main()
{
	tree_t *root_node=NULL;
	char element = 20;
	tree_t* node_found = NULL;

	// Create Ordered Binary Tree
	// root_node = create_new_node(30);
	// root_node->right_node = create_new_node(40);
	// root_node->left_node = create_new_node(20);
	// root_node->left_node->right_node = create_new_node(25);
	// root_node->left_node->left_node = create_new_node(10);
	// root_node->left_node->left_node->right_node = create_new_node(15);
	// root_node->left_node->left_node->left_node = create_new_node(5);
	// root_node->right_node->left_node = create_new_node(35);
	// root_node->right_node->right_node = create_new_node(45);
	// root_node->right_node->right_node->left_node = create_new_node(42);
	// root_node->right_node->right_node->left_node->right_node = create_new_node(43);


	insert(&root_node, 30);
	// insert(&root_node, 40);
	// insert(&root_node, 20);
	// insert(&root_node, 25);
	// insert(&root_node, 10);

	// insert(&root_node, 15);
	// insert(&root_node, 5);
	// insert(&root_node, 35);
	// insert(&root_node, 45);
	// insert(&root_node, 42);

	// insert(&root_node, 43);
	// insert(&root_node, 12);
	// insert(&root_node, 23);
	// insert(&root_node, 27);
	// insert(&root_node, 22);

	// insert(&root_node, 24);

	printf("\nPre Order Traversal data follow as: ");
	printf("\nTotal number of nodes: %d", pre_order_traversal(root_node));



	return 0;
}