#include <stdio.h> 
#include <stdlib.h> 
  
// A Linked List Node 
typedef struct Node 
{ 
    int data; 
    struct Node *right; 
    struct Node *down; 
} Node;

/* Function to print nodes in the flattened linked list */
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->down; 
    } 
} 

/* A utility function to insert a new node at the begining 
   of linked list */
void push (Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = (Node *) malloc(sizeof(Node)); 
    new_node->right = NULL; 
  
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list off the new node */
    new_node->down = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
    //printf("Push: %d\n", (*head_ref)->data);
} 
  

Node* merge_sort(Node *root, Node *right)
{
    Node *temp=NULL;
    printf("\nmerge_sort: Printing root: ");
    printList(root);
    printf("\nmerge_sort: Printing right node: ");
    printList(right);
    while(root != NULL && right != NULL)
    {
        if(root->data <= right->data)
        {
            push(&temp, root->data);
            root= root->down;
        }
        else{
            push(&temp, right->data);
            right= right->down;
        }
    }
    while(right != NULL)
    {
        push(&temp, right->data);
        right= right->down;
    }
    while(root != NULL)
    {
        push(&temp, root->data);
        root= root->down;
    }

    while(temp != NULL)
    {
        push(&root, temp->data);
        temp = temp->down;
    }
    //printf("\nmerge_sort: Printing sorted node: ");
    //printList(root);
    return root;
    //printList(root);
}

Node* flatten(Node *root)
{
    
    if(root->right == NULL )
    {
        printf("Hello\n");
        return root;
    }
    root->right = flatten(root->right);
    //printf("\nflatten: Printing root: ");
    //printList(root);
    //printf("\nflatten: Printing right node: ");
    //printList(root->right);
    return(merge_sort(root, root->right));
}



// Driver program to test above functions 
int main() 
{ 
    Node* root = NULL; 
  
    /* Let us create the following linked list 
       5 -> 10 -> 19 -> 28 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
    */
    push( &root, 30 ); 
    push( &root, 8 ); 
    push( &root, 7 ); 
    push( &root, 5 ); 
  
    push( &( root->right ), 20 ); 
    push( &( root->right ), 10 ); 
  
    push( &( root->right->right ), 50 ); 
    push( &( root->right->right ), 22 ); 
    push( &( root->right->right ), 19 ); 
  
    push( &( root->right->right->right ), 45 ); 
    push( &( root->right->right->right ), 40 ); 
    push( &( root->right->right->right ), 35 ); 
    push( &( root->right->right->right ), 28 ); 

    push( &( root->right->right->right->right ), 223 ); 
    push( &( root->right->right->right->right ), 200 ); 
    push( &( root->right->right->right->right ), 150 ); 
    push( &( root->right->right->right->right ), 130 ); 
    push( &( root->right->right->right->right ), 90); 
    push( &( root->right->right->right->right ), 70 ); 
    push( &( root->right->right->right->right ), 23 ); 
    push( &( root->right->right->right->right ), 1 ); 
    
  
   // printList(root); 
    // Let us flatten the list 
    root = flatten(root); 
  
    printf("\nMain: Sorted Array: ");
    // Let us print the flatened linked list 
    printList(root); 
  
    return 0; 
} 