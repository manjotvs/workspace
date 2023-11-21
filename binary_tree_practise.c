#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a>=b)?a:b)

typedef struct tree{
	char data;
	struct tree* left_node;
	struct tree* right_node;
}gtree;


char cal_height(gtree *node)
{
	if(node == NULL)
		return 0;
	return((MAX(cal_height(node->right_node), cal_height(node->left_node))+1));
}

gtree* add_elements(gtree *root, char dat)
{
	if( root == NULL )
	{
		root = malloc(sizeof(gtree));
		memset((void*)root,0,sizeof(gtree));
		root->data = dat;
		root->left_node = NULL;
		root->right_node = NULL;
		return root;
	}
	if(root->data <= dat)
		root->right_node = add_elements(root->right_node, dat);
	else
		root->left_node = add_elements(root->left_node, dat);

	return root;
}

gtree* add_list_of_elements(gtree *root, char *dat, char size)
{
	int i = 0;
	while(i<size)
	{
		root = add_elements(root, dat[i++]);
	}
	return root;
}

void preorder_traversal(gtree* root)
{
	if(root)
	{
		printf(" %d",root->data);
		inorder_traversal(root->left_node);
		inorder_traversal(root->right_node);
	}
}


int main()
{
	gtree *root = NULL;
	//gtree *temp = NULL;
	char list[] = {1,2,3,4,5,6};
	root = add_list_of_elements(root, list, (sizeof(list) / sizeof(list[0])));
	printf("Number of elements in tree: %lu\n", (sizeof(list) / sizeof(list[0])));
	printf("\nInorder Traversal:");
	inorder_traversal(root);
	// printf("\nPreorder Traversal: ");
	// preorder_traversal(root);
	// printf("\nPostorder Traversal: ");
	// postorder_traversal(root);
	// printf("\n");
	// printf("\nLevelorder Traversal: ");
	// levelorder_traversal(root);
	// printf("\n");




	return 0;
}