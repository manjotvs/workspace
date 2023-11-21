#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}treeNode_t;

#define MAX(a,b) (a>b)?a:b
int maxDepth1(struct TreeNode* root)
{  
	static int i = 0;
	printf("count: %d\n",i++ );
    if(root == NULL)
        return 0;
    return((MAX(maxDepth(root->left),maxDepth(root->right)))+1);
}

int maxDepth(struct TreeNode* root) {
    int left, right;
    static int i = 0;
	printf("count: %d\n",i++ );
    if (root == NULL) 
        return 0;
    left = maxDepth(root->left);
    right = maxDepth(root->right);
    return 1 + ((left>right)?left:right);
}

int main()
{
	treeNode_t root;
	root.val = 1;
	treeNode_t child1;
	child1.val = 2;
	child1.left = NULL;
	child1.right = NULL;
	root.left = &child1;
	root.right = NULL;
	printf("Depth: %d",maxDepth(&root));
}