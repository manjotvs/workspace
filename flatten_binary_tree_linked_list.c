#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Time Complexity O(n) = n^2; Adding elements and traversing thru trees
 * Space Complexity O(n) = n
 */

#define MAX(a,b) ((a>=b)?a:b)

typedef struct tree{
	char val;
	struct tree* left;
	struct tree* right;
}gtree;


gtree* add_elements(gtree *root, int dat)
{
	if( root == NULL )
	{
		root = (gtree*) malloc(sizeof(gtree));
		memset((void*)root,0,sizeof(gtree));
		root->val = dat;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	root->right = add_elements(root->right,dat);
	root->left = NULL;

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

gtree* preorder_traversal(gtree* root, gtree* head)
{
    if(root)
    {
        head = add_elements(head, root->val);
        preorder_traversal(root->left, head);
        preorder_traversal(root->right, head);
    }
    return head;
}

void flatten(gtree* root)
{    
    if(root == NULL) return;
    gtree* head = NULL;
    head = preorder_traversal(root, head);
    root->right = head->right;
    root->left = head->left;
}


void traversal(gtree *root)
{
	if(root != NULL)
	{
		printf("%d ",root->val );
		traversal(root->right);
	}
}


int main()
{
	gtree *root = NULL;
	//gtree *temp = NULL;
	char list[] = {1,2,3,4,5,6};
	root = add_list_of_elements(root, list, (sizeof(list) / sizeof(list[0])));
	printf("Number of elements in tree: %lu\n", (sizeof(list) / sizeof(list[0])));
	flatten(root);
	printf("Traversal: ");
	traversal(root);
	printf("\n");

	return 0;
}