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
	char i = 0;
	while(i<size)
	{
		root = add_elements(root, dat[i++]);
	}
	return root;
}

void inorder_traversal(gtree *root)
{
	if(root != NULL)
	{
		inorder_traversal(root->left_node);
		printf("%d ",root->data );
		inorder_traversal(root->right_node);
	}

}


void preorder_traversal(gtree *root)
{
	if(root != NULL)
	{
		printf("%d ",root->data );
		preorder_traversal(root->left_node);
		preorder_traversal(root->right_node);
	}
}

void postorder_traversal(gtree *root)
{
	if(root != NULL)
	{
		postorder_traversal(root->left_node);
		postorder_traversal(root->right_node);
		printf("%d ",root->data );
	}
}

void lol_traversal(char h, gtree* root)
{
	if(root == NULL)
		return;
	if(h == 1)
		printf("%d ", root->data);
	else if(h>1)
	{
		lol_traversal(h-1, root->left_node);
		lol_traversal(h-1, root->right_node);
	}
}

/* BFS- Breadth First Search */
void levelorder_traversal(gtree *root)
{
	char h = cal_height(root);
	for(char i=1; i<=h;i++)
	{
		lol_traversal(i,root);
	}
}



gtree* search_node(gtree *root, char dat)
{
	if(root == NULL)
		return NULL;
	if(root->data == dat)
		return root;
	if(root->data < dat)
		return(search_node(root->right_node, dat));
	else
		return(search_node(root->left_node, dat));

	return NULL;
}


/** Multiple cases are possible for deleting a node in tree follow as:
  * a) Delete a node with no child.
  * b) Delete a node with a child.
  * c) Delete a node with two children.
  */

gtree* delete_node(gtree *root, char dat)
{
	gtree *prev_node = NULL;
	gtree *curr_node = NULL;
	gtree *new_node = NULL;
	
	curr_node = root;
	while(curr_node != NULL)
	{
		if(curr_node->data == dat)
		{
			break;
		}
		prev_node = curr_node;
		if(curr_node->data > dat)
		{
			curr_node = curr_node->left_node;
		}
		else
		{
			curr_node = curr_node->right_node;
		}
	}
	// We can avoid this line as new_node is already node and we are already checking for other possible cases.
	if(curr_node->left_node == NULL && curr_node->right_node == NULL)
	{
		//printf("Found a node with no children: %d\n", curr_node->data);
		new_node = NULL;
	}

	if(curr_node->left_node != NULL && curr_node->right_node != NULL)
	{
		gtree *temp;
		//printf("Found a node with two children: %d\n", curr_node->data);
		new_node = curr_node->right_node;
		while(new_node->left_node != NULL)
		{
			new_node = new_node->left_node;
		}
		memset((void*)temp,0,sizeof(gtree));
		temp = malloc(sizeof(gtree));
		temp->data = new_node->data;
		//printf("Found its predecessor for replacement: %d\n",new_node->data);
		temp->right_node = delete_node(curr_node->right_node, new_node->data);
		//printf("Inorder Traversal: ");
		// inorder_traversal(temp->right_node);
		// printf("\n");

		temp->left_node = curr_node->left_node;
		// = curr_node->right_node;
		
	
		new_node = temp;
		//printf("Found its predecessor for replacement: %d\n",new_node->data);
	}

	if( curr_node->left_node == NULL && curr_node->right_node != NULL)
	{
		new_node = curr_node->right_node;
	}
	else if( curr_node->left_node != NULL && curr_node->right_node == NULL)
	{
		new_node = curr_node->left_node;
	}

	if(prev_node == NULL)
	{
		//printf("Returning as prev_node was NULL\n");
		return new_node;
	}
	else if(prev_node->right_node == curr_node)
	{
		//printf("Assigning a new_node to right_node of parent node: %d\n", prev_node->data);
		prev_node->right_node = new_node;
	}
	else if(prev_node->left_node == curr_node)
	{
		//printf("Assigning a new_node to left_node of parent node: %d\n", prev_node->data);
		prev_node->left_node = new_node;
	}

	// printf("Inorder Traversal: ");
	// inorder_traversal(root);
	// printf("\n");
	// printf("Exiting!!!\n");
	free(curr_node);
	//printf("Returning with node %d\n", root->data);
	return root;
}



char cal_nodes(gtree *node)
{
	if(node == NULL)
		return 0;
	//printf("%d\n", node->data);
	//return((cal_nodes(node->right_node) + cal_nodes(node->left_node)+1),printf("ret: %d\n", node->data));
	return((cal_nodes(node->right_node) + cal_nodes(node->left_node)+1));
}

char cal_int_nodes(gtree *node)
{
	if(node == NULL)
		return 0;
	else if(node->left_node == NULL && node->right_node == NULL)
		return 0;
	else
		return((cal_int_nodes(node->right_node) + cal_int_nodes(node->left_node)+1));
}

char cal_ext_nodes(gtree *node)
{
	if(node == NULL)
		return 0;
	else if(node->left_node != NULL || node->right_node != NULL)
		return((cal_ext_nodes(node->right_node) + cal_ext_nodes(node->left_node)+1));
	return 0;
}

char cal_ext_nodes2(gtree *node)
{
	if(node == NULL)
		return 0;
	else if(node->left_node == NULL && node->right_node == NULL)
		return 1;
	else
		return((cal_ext_nodes2(node->right_node) + cal_ext_nodes2(node->left_node)));
}

char find_smallest_element(gtree *node)
{
	if(node->left_node == NULL)
		return node->data;
	return(find_smallest_element(node->left_node));
}
char find_largest_element(gtree *node)
{
	if(node->right_node == NULL)
		return node->data;
	return(find_largest_element(node->right_node));
}

gtree* find_mirror_image(gtree *node)
{
	if(node == NULL)
		return node;
	gtree *temp;
	temp = node->right_node;
	node->right_node = node->left_node;
	node->left_node = temp;
	find_mirror_image(node->left_node);
	find_mirror_image(node->right_node);
	return node;
}

int main()
{
	gtree *root = NULL;
	gtree *temp = NULL;
	char list[] = {30,15,45,40,55,20,10,5,8,2,35,42,32,13,14,11,31,56,57,58,59,60};
	root = add_list_of_elements(root, list, (sizeof(list) / sizeof(list[0])));
	printf("Number of elements in tree: %lu\n", (sizeof(list) / sizeof(list[0])));
	printf("\nInorder Traversal: ");
	inorder_traversal(root);
	printf("\nPreorder Traversal: ");
	preorder_traversal(root);
	printf("\nPostorder Traversal: ");
	postorder_traversal(root);
	printf("\n");
	printf("\nLevelorder Traversal: ");
	levelorder_traversal(root);
	printf("\n");


	char dat = 35;
	if((temp = search_node(root, dat)) != NULL)
	{
		printf("Found the element: %d\n", temp->data);
	}
	else
	{
		printf("This element(%d) is not given in given tree\n", dat);
	}

	printf("Delete this element: %d\n", dat);
	root = delete_node(root, dat);
	printf("Inorder Traversal: ");
	inorder_traversal(root);
	printf("\n");
	printf("Height of tree: %d\n", cal_height(root));
	printf("Number of elements in a tree: %d\n", cal_nodes(root));
	printf("Number of internal elements in a tree: %d\n", cal_int_nodes(root));
	printf("Number of external elements in a tree: %d\n", cal_ext_nodes2(root));
	printf("Smallest elemente in a tree: %d\n", find_smallest_element(root));
	printf("Largest elemente in a tree: %d\n", find_largest_element(root));
	find_mirror_image(root);
	printf("Inorder Traversal: ");
	inorder_traversal(root);
	printf("\n");

	return 0;
}