#include <stdio.h>
#include <stdlib.h>
//#include<string.h>
#define MAX(a,b) ((a > b)?a:b)


typedef struct node
{
	struct node *left_node;
	char data;
	struct node *right_node;
}node_t;

char find_height(node_t *t)
{
	char lheight=0;
	char rheight=0;
	if(t == NULL)
		return -1;
	lheight = find_height(t->left_node);
	rheight = find_height(t->right_node);

	return(MAX(lheight,rheight) + 1);
}

char find_number_of_internal_nodes(node_t *t)
{
	if(t == NULL)
		return 0;
	if(t->left_node == NULL && t->right_node == NULL)
		return 0;
	else return(find_number_of_internal_nodes(t->left_node) + find_number_of_internal_nodes(t->right_node) + 1);
}

char find_number_of_external_nodes(node_t *t)
{
	if(t == NULL)
		return 0;
	if(t->left_node == NULL && t->right_node == NULL)
		return 1;
	else return(find_number_of_external_nodes(t->left_node) + find_number_of_external_nodes(t->right_node));
}

char find_number_of_nodes(node_t *t)
{
	char l=0;
	char r=0;
	if(t == NULL)
		return 0;
	l= find_number_of_nodes(t->left_node);
	r = find_number_of_nodes(t->right_node);

	return(l + r + 1);
}

node_t* find_mirror_image(node_t *t)
{
	node_t *temp;
	temp = t;
	if(t != NULL)
	{

		find_mirror_image(t->left_node);
		find_mirror_image(t->right_node);
		temp = t->left_node;
		t->left_node = t->right_node;
		t->left_node = temp;
	}

	return(t);
}

void inorder_traversal(node_t *t)
{
	if(t != NULL)
	{
		inorder_traversal(t->left_node);
		printf("%d ", t->data);
		inorder_traversal(t->right_node);
	}
}

node_t* search_tree(node_t *t, char val)
{
	if(t != NULL)
	{
		if(t->data == val)
		{
			return t;
		}
		else
		{
			if(val < t->data)
			{
				if( t->left_node != NULL )
					return(search_tree(t->left_node, val));
			}
			else
			{
				if( t->right_node != NULL )
					return(search_tree(t->right_node, val));
			}
		}
	}
	return NULL;
}

node_t* new_node(char val)
{
	node_t *n = malloc(sizeof(node_t));
	n->left_node = NULL;
	n->right_node = NULL;
	n->data = val;
	return n;
}

node_t* insert_node( node_t *t, char val)
{
	if(t == NULL) return new_node(val);

	if(val < t->data)
		t->left_node = insert_node(t->left_node, val);
	else
		t->right_node = insert_node(t->right_node, val);

	return t;
}


node_t* delete_node(node_t *n, char val)
{
	if(n == NULL)
	{
		printf("Tree is empty!!!\n");
		return -1;
	}

	node_t *temp, *parent, *largest_node, *psuc, *t;
	node_t *next_node;
	temp = n;
	parent = temp;
	while( temp!= NULL && temp->data != val )
	{
		printf("Changing temp %d\n", temp->data );
		parent = temp;
		temp = (val > temp->data)? temp->right_node: temp->left_node;
	}
	if(temp == NULL)
	{
		printf("Node is not present in tree!!!\n");
		return -1;
	}
	if(temp->right_node != NULL && temp->left_node != NULL)
	{
		printf("Found a node with two child: %d %d %d\n",temp->data, temp->right_node->data, temp->left_node->data);
		psuc = temp;
		largest_node = temp->left_node;
		while(largest_node->right_node != NULL)
		{
			printf("Possible largest_node: %d %d\n", largest_node->data, psuc->data );
			psuc = largest_node;
			largest_node = largest_node->right_node;
		}
		printf("Found a largest node: %d %d\n",largest_node->data, psuc->data);
		largest_node->right_node = temp->right_node;
		psuc->right_node = NULL;
		t=largest_node;
		while(t->left_node != NULL)
		{
			t = t->left_node;
		}
		t->left_node = temp->left_node;
		next_node = largest_node;
	}
	else if(temp->right_node != NULL)
	{
		printf("Deleting a node with right child: %d %u\n", temp->data, temp->right_node->data);
		next_node = temp->right_node;

	}
	else if(temp->right_node == NULL && temp->left_node != NULL)
	{
		printf("Deleting a node with left child: %d %d\n", temp->data, temp->left_node->data);
		next_node = temp->left_node;
	}
	else
	{
		printf("Deleting a node with no child: %d\n", temp->data);
		next_node = NULL;
	}
	if(parent->left_node == temp)
	{
		printf("hello\n");
		parent->left_node = next_node;
	}
	else if(parent->right_node == temp)
	{
		printf("world\n");
		parent->right_node = next_node;
	}
	else
	{
		printf("hi: %d\n", next_node->data);
		parent = next_node;
	}
	free(temp);
	return parent;
}



int main()
{
	node_t *tree = NULL;
	node_t *temp = NULL;
	tree = insert_node( tree, 21);
	char n = 21;
	insert_node( tree, 5);
	insert_node( tree, 10);
    insert_node( tree, 3);
	// insert_node( tree, 7);
	// insert_node( tree, 6);
	// insert_node( tree, 8);
	// insert_node( tree, 15);
	// insert_node( tree, 12);
	// insert_node( tree, 13);
	// insert_node( tree, 19);
	// insert_node( tree, 20);
	// insert_node( tree, 17);
	// insert_node( tree, 16);
	// insert_node( tree, 18);
	// insert_node( tree, 2);
	// insert_node( tree, 4);
	// insert_node( tree, 24);
	temp = search_tree(tree, n);
	if(temp != NULL)
		printf("Node found: %d\n", temp->data);
	else
		printf("Invalid Node\n");

	printf("All nodes follow as: \n");
	inorder_traversal(tree);
	printf("\n");

	printf("\nDelete this node: %d\n", n);
	tree = delete_node(tree, n);
	printf("All nodes follow as: \n");
	inorder_traversal(tree);
	printf("\n");

	printf("Height of the tree: %d\n",find_height(tree));
	printf("Total number of nodes in a tree: %d\n",find_number_of_nodes(tree));
	printf("Total number of internal nodes in a tree: %d\n",find_number_of_internal_nodes(tree));
	printf("Total number of external nodes in a tree: %d\n",find_number_of_external_nodes(tree));


	tree = find_mirror_image(tree);
	printf("All nodes of mirror image follow as: \n");
	inorder_traversal(tree);
	printf("\n");
	//free(tree);
	//free(tree->left_node);
	//free(tree->right_node);
	return 0;
}