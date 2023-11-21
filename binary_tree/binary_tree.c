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

tree_t *create_new_node(char data)
{
	tree_t *new_node;
	new_node = (tree_t*)malloc(sizeof(tree_t));
	memset(new_node, 0, sizeof(tree_t));
	new_node->data = data;
	new_node->right_node = NULL;
	new_node->left_node = NULL;
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

void in_order_traversal(tree_t *itr)
{
	if(itr!= NULL)
	{
		in_order_traversal(itr->left_node);
		printf(" %d", itr->data );
		in_order_traversal(itr->right_node);
	}
	return;
}

void post_order_traversal(tree_t *itr)
{
	if(itr!= NULL)
	{
		post_order_traversal(itr->left_node);
		post_order_traversal(itr->right_node);
		printf(" %d", itr->data );
	}
	return;
}

tree_t* search(tree_t *itr, char element)
{
	if(itr!= NULL)
	{
		if(itr->data == element)
			return itr;
		if(element < itr->data)
		 return (search(itr->left_node, element));
		else
		 return (search(itr->right_node, element));
	}
	return NULL;
}

void insert(tree_t **root_node, char data)
{
	tree_t *itr;
	itr = *root_node;
	if(itr == NULL)
	{
		itr = create_new_node(data);
		//printf("Data: %d\n", itr->data);
		*root_node = itr;
		return;
	}
 	if(itr != NULL)
	{
		if(data > itr->data)
		{
			//printf("Right Data: %d\n", data);
			insert(&itr->right_node, data);
		}
		else
		{
			//printf("Left Data: %d\n", data);
			insert(&itr->left_node, data);
		}
	}
}


void delete(tree_t **root_node, char data)
{
	tree_t *itr;
 	tree_t *node_to_delete = NULL;
 	tree_t *parent_node = NULL;
	
	itr = *root_node;

	while(itr != NULL)
	{
		if(itr->data == data)
			break;
		parent_node = itr;
		if(data > itr->data)
			itr = itr->right_node;
		else
			itr = itr->left_node;
	}
	if(itr == NULL)
		return;

	/* Delete a leaf node */
	/* If leaf node is the root node then NULL the root node before returning */
	if(itr->right_node == NULL && itr->left_node == NULL)
	{

		printf("\nFound the leaf node(%d) to delete!",itr->data);
		if(parent_node == NULL)
		{
			*root_node = NULL;
		}
		else
		{
			//printf("\nParent node(%d) & Leaf node(%d)",parent_node->data, itr->data );
			if(parent_node->right_node == itr)
			{
				parent_node->right_node = NULL;
			}
			else
			{
				parent_node->left_node = NULL;
			}
		}
	}
	/* Delete a node with a child */
	else if(itr->right_node == NULL && itr->left_node != NULL)
	{
		printf("\nFound a node(%d) with child to delete!",itr->data);
		if(parent_node->right_node == itr)
		{
			parent_node->right_node = itr->left_node;
		}
		else
		{
			parent_node->left_node = itr->left_node;
		}
	} 
	else if(itr->right_node != NULL && itr->left_node == NULL)
	{
		printf("\nFound a node(%d) with child to delete!",itr->data);
		if(parent_node->right_node == itr)
		{
			parent_node->right_node = itr->right_node;
		}
		else
		{
			parent_node->left_node = itr->right_node;
		}

	}
	else
	{
		printf("Find left most node to replace with delete node\n");
		tree_t *temp;
		temp = itr->right_node;
		while(temp->left_node!= NULL)
		{
			temp = temp->left_node;
		}
		printf("Parent Node(%d), node_to_delete(%d), node to replace(%d)\n",
			parent_node->data, itr->data, temp->data );
		if(parent_node->right_node == itr)
			parent_node->right_node->data = temp->data;
		else
			parent_node->left_node->data = temp->data;
		return(delete(&(itr->right_node),temp->data));

	}
	free(itr);

}

void delete_1(tree_t **root_node, char data)
{
	tree_t *itr;
 	tree_t *ptr = NULL;
 	tree_t *parent_node = NULL;
	
	itr = *root_node;

	while(itr != NULL)
	{
		if(itr->data == data)
			break;
		parent_node = itr;
		if(data > itr->data)
			itr = itr->right_node;
		else
			itr = itr->left_node;
	}
	if(itr == NULL)
		return;

	/* Delete a leaf node */
	/* If leaf node is the root node then NULL the root node before returning */
	if(itr->right_node == NULL && itr->left_node == NULL)
	{

		printf("\nFound the leaf node(%d) to delete!",itr->data);
		if(parent_node == NULL)
		{
			*root_node = NULL;
		}
	}
	/* Delete a node with a child */
	else if(itr->right_node == NULL && itr->left_node != NULL)
	{
		ptr = itr->left_node;
	} 
	else if(itr->right_node != NULL && itr->left_node == NULL)
	{
		ptr = itr->right_node;

	}
	else
	{
		//printf("Find left most node to replace with delete node\n");
		tree_t *temp;
		temp = itr->right_node;
		while(temp->left_node!= NULL)
		{
			temp = temp->left_node;
		}
		printf("\nParent Node(%d), node_to_delete(%d), node to replace(%d)\n",
			parent_node->data, itr->data, temp->data );
		if(parent_node->right_node == itr)
			parent_node->right_node->data = temp->data;
		else
			parent_node->left_node->data = temp->data;
		return(delete_1(&(itr->right_node),temp->data));

	}
	if(parent_node->right_node == itr)
	{
		parent_node->right_node = ptr;
	}
	else
	{
		parent_node->left_node = ptr;
	}
	free(itr);

}

char find_height_of_tree(tree_t *itr)
{
	if(itr == NULL)
		return 0;
	return(MAX(find_height_of_tree(itr->right_node), find_height_of_tree(itr->left_node))+1);
}


char find_number_of_internal_nodes(tree_t *itr)
{
	// if(itr->left_node == NULL && itr->right_node == NULL)
	// 	return 0;
	if(itr == NULL)
	{
		return 0;
	}
	if(itr->left_node == NULL && itr->right_node == NULL)
		return 0;
	return(find_number_of_internal_nodes(itr->right_node) + find_number_of_internal_nodes(itr->left_node) +1);

}

char find_number_of_external_nodes(tree_t *itr)
{
	// if(itr->left_node == NULL && itr->right_node == NULL)
	// 	return 0;
	if(itr == NULL)
	{
		return 0;
	}
	if(itr->left_node == NULL && itr->right_node == NULL)
		return 1;
	return(find_number_of_external_nodes(itr->right_node) + find_number_of_external_nodes(itr->left_node));

}

void mirror_image(tree_t * itr)
{
	tree_t *temp;
	if(itr != NULL)
	{
		mirror_image(itr->left_node);
		mirror_image(itr->right_node);
		temp = itr->right_node;
		itr->right_node = itr->left_node;
		itr->left_node = temp;
	}	
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
	insert(&root_node, 40);
	insert(&root_node, 20);
	insert(&root_node, 25);
	insert(&root_node, 10);

	insert(&root_node, 15);
	insert(&root_node, 5);
	insert(&root_node, 35);
	insert(&root_node, 45);
	insert(&root_node, 42);

	insert(&root_node, 43);
	insert(&root_node, 12);
	insert(&root_node, 23);
	insert(&root_node, 27);
	insert(&root_node, 22);

	insert(&root_node, 24);

	printf("\nPre Order Traversal data follow as: ");
	printf("\nTotal number of nodes: %d", pre_order_traversal(root_node));

	// printf("\nIn Order Traversal data follow as: ");
	// in_order_traversal(root_node);

	// printf("\nPost Order Traversal data follow as: ");
	// post_order_traversal(root_node);
	// printf("\n");

	node_found = search(root_node, element);

	if(node_found!=NULL)
		printf("\nFound an element(%d) in Ordered Binary Tree!",node_found->data );
	else
		printf("\nNot found!!!");

	//delete(&root_node, element);
	delete_1(&root_node, element);


	printf("\nPre Order Traversal data follow as: ");
	pre_order_traversal(root_node);
	printf("\n");

	printf("Height of tree: %d\n", find_height_of_tree(root_node) );

	printf("Number of internal nodes: %d\n", find_number_of_internal_nodes(root_node) );
	printf("Number of external nodes: %d\n", find_number_of_external_nodes(root_node) );

	mirror_image(root_node);
	printf("\nPre Order Traversal data after mirror image follow as:");
	pre_order_traversal(root_node);
	getchar();

	return 0;
}