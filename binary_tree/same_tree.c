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

bool same_tree(tree_t *itr1, tree_t *itr2)
{
	if(itr1 == NULL && itr2 == NULL)
		return true;
	else if(itr1 ==  NULL)
		return false;
	else if(itr2 == NULL)
		return false;

	if(itr1->data != itr2->data)
		return false;
	return(same_tree(itr1->right_node, itr2->right_node) &&
	same_tree(itr1->left_node, itr2->left_node));
}

int main()
{
	tree_t *tree1 = NULL;
	tree_t *tree2 = NULL;
	char element = 20;
	tree_t* node_found = NULL;

	// Create Ordered Binary Tree
	insert(&tree1, 30);
	insert(&tree1, 40);
	insert(&tree1, 20);
	insert(&tree1, 25);
	insert(&tree1, 10);

	insert(&tree1, 15);
	insert(&tree1, 5);
	insert(&tree1, 35);
	insert(&tree1, 45);
	insert(&tree1, 42);

	insert(&tree2, 30);
	insert(&tree2, 40);
	insert(&tree2, 20);
	insert(&tree2, 25);
	insert(&tree2, 10);

	insert(&tree2, 15);
	insert(&tree2, 5);
	insert(&tree2, 35);
	insert(&tree2, 45);
	insert(&tree2, 42);


	printf("Pre Order Traversal data for tree1 follow as: ");
	pre_order_traversal(tree1);

	printf("\nPre Order Traversal data for tree2 follow as: ");
	pre_order_traversal(tree2);

	printf("\nSame tree(0: false or 1: true) --> %d\n", same_tree(tree1, tree2));

	//same_tree()



	return 0;
}