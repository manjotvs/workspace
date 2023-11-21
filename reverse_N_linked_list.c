#include <stdio.h>
#include <stdlib.h>

//Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

/* Linked list node */
typedef struct Node_t 
{ 
    int data; 
    struct Node_t *next; 
}Node; 
  
/* Function to create a new node with given data */
Node *newNode(int data) 
{ 
    Node *new_node = malloc(sizeof(Node)); 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
} 
  
  
// A utility function to print a linked list 
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d", node->data); 
        node = node->next; 
    } 
    printf("\n"); 
} 

void reverse(Node *a , Node*b)
{
    int temp;
    while(a!= NULL && b != NULL)
    {
        temp = a->data;
        a->data = b->data;
        b->data = temp;
        a= a->next;
        b=b->next;
    }

}

Node* reverse_k_nodes(Node *head)
{
    if(head->next == NULL)
        return head;
    reverse_k_nodes(head->next);

    printf("reverse_k_nodes: %d %d\n",head->data, head->next->data);
    //while(k --)
    reverse(head, head->next);
    printf("reverse_k_nodes: %d %d\n",head->data, head->next->data);
    return NULL;
}

  
/* Driver program to test above function */
int main(void) 
{ 
    Node *head = newNode(1); 
    head->next = newNode(9); 
    head->next->next = newNode(9); 
    head->next->next->next = newNode(8); 
    head->next->next->next->next = newNode(7); 
    head->next->next->next->next->next = newNode(6); 
  
    printf("List is "); 
    printList(head); 
  
    reverse_k_nodes(head); 
  
    printf("\nResultant list is "); 
    printList(head); 
  
    return 0; 
} 