#include <stdio.h>
#include <stdlib.h>

//Number is represented in linked list such that each digit corresponds to a node in linked list. Add 1 to it. 
//For example 1999 is represented as (1-> 9-> 9 -> 9) and adding 1 to it should change it to (2->0->0->0)



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

uint8_t addWithCarry(Node *root)
{
    char sum = 0;
    //printf("Hi\n");
    if(root == NULL)
        return 1;
    sum = root->data + addWithCarry(root->next);
    root->data = sum %10;
    return sum/10;
}


Node* addOne(Node *root)
{
    //printf("Hello\n");
    uint8_t flag=0;
    flag = addWithCarry(root);
    if(flag)
    {
        Node *carry;
        carry = malloc(sizeof(Node));
        carry->data = 1;
        carry->next = root;
        return carry;
    }
    return root;
}
  
/* Driver program to test above function */
int main(void) 
{ 
    Node *head = newNode(1); 
    head->next = newNode(9); 
    head->next->next = newNode(9); 
    head->next->next->next = newNode(8); 
  
    printf("List is "); 
    printList(head); 
  
    head = addOne(head); 
  
    printf("\nResultant list is "); 
    printList(head); 
  
    return 0; 
} 