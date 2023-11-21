#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (a>b?a:b)

typedef struct tree{
	int val;
	struct tree* right;
	struct tree* left;
}tree_t;

typedef struct node{
	int val;
	struct node* next;
}node_t;
node_t *ll = NULL;

tree_t* addNewNode(int data)
{
	tree_t *node;
	node = (tree_t*)malloc(sizeof(tree_t));
	node->left = NULL;
	node->right = NULL;
	node->val = data;
	return node;
}

node_t* addNewNodeList(int data)
{
	node_t *node;
	node = (node_t*)malloc(sizeof(node_t));
	node->next = NULL;
	node->val = data;
	return node;
}

void createBST(tree_t **base, int data)
{
	tree_t *itr;
	itr = *base;

	if(itr == NULL)
	{
		itr = addNewNode(data);
		*base = itr;
		return;
	}
	if(itr != NULL)
	{
		if( data < itr->val)
		{
			createBST(&(itr->left), data);
		}
		else
		{
			createBST(&(itr->right), data);
		}
	}
}

uint8_t treeHeight(tree_t *root)
{
	if(root == NULL)
		return 0;
	return(MAX(treeHeight(root->left), treeHeight(root->right)) + 1);
}


void preOrderTraversal(tree_t *root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d ",root->val );
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(tree_t *root)
{
	if(root == NULL)
	{
		return;
	}
	inOrderTraversal(root->left);
	printf("%d ",root->val );
	inOrderTraversal(root->right);
}

void createList(node_t **root, int data)
{
	node_t* itr;
	node_t* new_node;
	itr = *root;
	new_node = addNewNodeList(data);
	if(itr == NULL)
	{
		itr = new_node;
		*root = itr;
		return;
	}
	while(itr->next != NULL)
	{
		itr = itr->next;
	}
	itr->next = new_node;
}



void traverseList(node_t *itr)
{
	while(itr!= NULL)
	{
		printf("%d ", itr->val);
		itr = itr->next;
	}
	printf("\n");
}

void createHeightBalancedTree(tree_t** base, int *arr, char start, char end)
{
	char mid = ((start + end)/2);
	if(start >end)
	{
		return;
	}
	//printf("Start: %d, End: %d & Mid: %d\n", start, end, mid );

	tree_t *itr = *base;
	if(itr == NULL)
	{
		itr = addNewNode(arr[mid]);
		*base = itr;
	}
	createHeightBalancedTree(&((*base)->left), arr, start, mid - 1);
	createHeightBalancedTree(&((*base)->right), arr, mid+1, end);
	//printf("mid: %d\n",mid);
}
tree_t *BST = NULL;
tree_t* createHeightBalancedTreeUsingInorderTraversal( int left, int right)
{
	
	printf("left1: %d, right: %d\n",left,right);

	if(left > right)
	{
		printf("RETURN\n");
		return NULL;
	}
	int mid = (left+right)/2;
	printf("mid :%d\n",mid );

	tree_t *left_node =  createHeightBalancedTreeUsingInorderTraversal(left, mid-1);
	
	tree_t *itr = addNewNode(ll->val);
	itr->left = left_node;
	printf("left2: %d, right: %d\n",left,right);
	if(ll!= NULL)
	ll = ll->next;
	itr->right = createHeightBalancedTreeUsingInorderTraversal( mid+1, right);
	//= ll;
	printf("itr: %d\n", itr->val);
	return itr;
}


int main()
{
	tree_t *root = NULL;
	
	int arr[] = {-6, -3, -2, 1, 5, 10, 34 };
	char size = (sizeof(arr) / sizeof(arr[0]));


	// Create a Balanced Binary Tree
	char i = 0;
	while(i < size)
		createBST(&root, arr[i++]);
	// printf("Binary Tree looks like: ");
	// inOrderTraversal(root);
	// printf("\n");
	// printf("Height of BST: %d\n",treeHeight(root) );

	// // Create a Height Balanced Binary Tree
	// root = NULL;
	// createHeightBalancedTree(&root, arr, 0, size-1);
	// printf("Height Balanced Binary Tree: ");
	// inOrderTraversal(root);
	// printf("\n");
	// printf("Height of BST: %d\n",treeHeight(root) );

	// Create a Height Balanced Binary Tree using in-order traversal
	// But, first lets create a linked list
	i=0;
	while(i < size)
		createList(&ll, arr[i++]);
	printf("Linked List: ");
	traverseList(ll);
	BST = createHeightBalancedTreeUsingInorderTraversal(0, 6);
	printf("Height Balanced Binary Tree: ");
	inOrderTraversal(BST);
	printf("\n");
	printf("Height of BST: %d\n",treeHeight(BST) );

	return 0;
}