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

bool is_bst_tree(tree_t *itr1, char data)
{
	// if(itr1 == NULL)
	// 	return true;
	if(itr1->left_node == NULL && itr1->right_node == NULL)
		return true;

	if(itr1->left_node != NULL && itr1->right_node != NULL)
	{
		if(((itr1->left_node->data <= itr1->data && itr1->left_node->data <= data)) &&
		 ((itr1->right_node->data > itr1->data && itr1->left_node->data > data)))
			return (is_bst_tree(itr1->left_node, data) && is_bst_tree(itr1->right_node, data));
		else
			return false;
	}

	if(itr1->left_node != NULL)
	{
	 	if(itr1->left_node->data > itr1->data && itr1->left_node->data > data) 
			return false;
		else
			return (is_bst_tree(itr1->left_node, data));
	}
	if(itr1->right_node != NULL)
	{
		if(itr1->right_node->data < itr1->data && itr1->right_node->data < data) 
			return false;
		else
			return (is_bst_tree(itr1->right_node, data));
	}

}

int isBSTUtil(tree_t* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBSTUtil(node->left_node, min, node->data-1) && // Allow only distinct values  
        isBSTUtil(node->right_node, node->data+1, max); // Allow only distinct values  
}  

int main()
{
	tree_t *root_node = NULL;
	char element = 20;
	tree_t* node_found = NULL;

	// Create Ordered Binary Tree
	root_node = create_new_node(10);
	root_node->right_node = create_new_node(20);
	root_node->left_node = create_new_node(5);
	root_node->left_node->right_node = create_new_node(8);
	root_node->left_node->left_node = create_new_node(3);
	root_node->right_node->right_node = create_new_node(25);
	root_node->right_node->left_node = create_new_node(1);
	
	printf("Pre Order Traversal data for tree1 follow as: ");
	pre_order_traversal(root_node);


	printf("\nSymmetric tree(0: false or 1: true) --> %d\n",isBSTUtil(root_node, -200, 200));

	//same_tree()



	return 0;
}