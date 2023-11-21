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
	new_node->data = data;
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
	itr = *root_node; 
	if(itr == NULL)
	{
		itr = create_new_node(val);
		*root_node = itr;
		return;
	}
	if(itr != NULL)
	{
		if(val > itr->data)
			insert(&(itr->right_node), val);
		else
			insert(&(itr->left_node), val);
	}
}

bool symmetric_tree(tree_t *itr1, tree_t *itr2)
{
	if(itr1 == NULL && itr2 == NULL)
		return true;
	else if(itr1 ==  NULL)
		return false;
	else if(itr2 == NULL)
		return false;

	if(itr1->data != itr2->data)
		return false;
	return(symmetric_tree(itr1->right_node, itr2->left_node) &&
	symmetric_tree(itr1->left_node, itr2->right_node));
}

int main()
{
	tree_t *root_node = NULL;
	char element = 20;
	tree_t* node_found = NULL;

	// Create Ordered Binary Tree
	root_node = create_new_node(1);
	root_node->right_node = create_new_node(2);
	root_node->left_node = create_new_node(2);
	//root_node->left_node->right_node = create_new_node(4);
	root_node->left_node->left_node = create_new_node(3);
	root_node->right_node->right_node = create_new_node(3);
	//root_node->right_node->right_node = create_new_node(4);
	
	printf("Pre Order Traversal data for tree1 follow as: ");
	pre_order_traversal(root_node);


	printf("\nSymmetric tree(0: false or 1: true) --> %d\n",symmetric_tree(root_node->right_node, root_node->left_node) );

	//same_tree()



	return 0;
}