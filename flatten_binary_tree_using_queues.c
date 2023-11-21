#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Time Complexity O(n) = n
 * Space Complexity O(n) = 1
 */

#define MAX(a,b) ((a>=b)?a:b)

typedef struct tree{
	char val;
	struct tree* left;
	struct tree* right;
}gtree;

char cal_height(gtree *node)
{
	if(node == NULL)
		return 0;
	return((MAX(cal_height(node->right), cal_height(node->left))+1));
}

/* Queue struct */
typedef struct node{
	gtree *node;
	struct node *next_node;
}node_t;

typedef struct queue
{
	node_t *front;
	node_t *rear;
	uint32_t count;
}queue_t;

/* Global Queue */
queue_t queue_g;
queue_t *queue_gptr = &queue_g;



node_t* create_queue_element(gtree *n)
{
	node_t* root = (node_t*) malloc(sizeof(node_t));
	memset((void*)root,0,sizeof(node_t));
	root->node = n;
	root->next_node = NULL;
	return root;
}


bool is_queue_empty()
{
	if(queue_gptr->rear == NULL || queue_gptr->front == NULL || queue_gptr->count == 0)
	{
		//printf("Queue is empty\n");
		return 0;
	}
	return 1;
}

/* Enqueue method for queue */
void enqueue(gtree* node)
{
	if(node == NULL) return;
	node_t* new_node = create_queue_element(node);
	if(!is_queue_empty())
	{
		printf("Initialzing Queue: %d\n",node->val);
		queue_gptr->front = queue_gptr->rear = new_node;
	}
	else
	{
		printf("Enqueued: %d\n",node->val);
		queue_gptr->rear->next_node = new_node;
		queue_gptr->rear = new_node;
	}
	queue_gptr->count++;
}

/* Dequeue method for queue */
gtree* dequeue()
{
	gtree* tree_node = NULL;
	node_t* temp = NULL;
	if(!is_queue_empty())
	{
		printf("Queue is empty\n");
		return tree_node;
	}
	else if(queue_gptr->rear == queue_gptr->front)
	{
		temp = queue_gptr->front;
		queue_gptr->rear = queue_gptr->front = NULL;
		queue_gptr->count = 0;
	}
	else
	{
		temp = queue_gptr->front;
		queue_gptr->front = queue_gptr->front->next_node;
		queue_gptr->count--;
	}
	tree_node = temp->node;
	printf("Dequeued: %d\n",tree_node->val);
	free(temp);
	return tree_node;
}


gtree* add_elements(gtree *root, char dat)
{
	if( root == NULL )
	{
		root = malloc(sizeof(gtree));
		memset((void*)root,0,sizeof(gtree));
		root->val = dat;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	if(root->val <= dat)
		 root->right = add_elements(root->right, dat);
	else
		 root->left = add_elements(root->left, dat);
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

void level_order_traversal(gtree* root)
{
	gtree* prev = NULL;
	gtree* curr = root;
    while(curr)
    {
        enqueue(curr->left);
        enqueue(curr->right);
        prev = curr;
        curr = dequeue();
        prev->left = NULL;
        prev->right = curr;
    }
}

void flatten(gtree* root)
{    
    if(root == NULL) return;
    level_order_traversal(root);
}


void traversal(gtree *root)
{
	if(root != NULL)
	{
		printf("%d ",root->val );
		traversal(root->right);
	}
}

void preorder_traversal(gtree *root)
{
	if(root != NULL)
	{
		printf("%d ",root->val );
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	}
}

void lol_traversal(char h, gtree* root)
{
	if(root == NULL)
		return;
	if(h == 1)
		printf("%d ", root->val);
	else if(h>1)
	{
		lol_traversal(h-1, root->left);
		lol_traversal(h-1, root->right);
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


int main()
{
	gtree *root = NULL;
	//gtree *temp = NULL;
	char list[] = {20,21,22,10,11,12,9,8};
	root = add_list_of_elements(root, list, (sizeof(list) / sizeof(list[0])));
	printf("Number of elements in tree: %lu\n", (sizeof(list) / sizeof(list[0])));

	printf("Level Traversal: ");
	levelorder_traversal(root);
	printf("\n");


	flatten(root);
	printf("Traversal: ");
	traversal(root);
	printf("\n");

	return 0;
}