// A C++ program to demonstrate deletion of last 
// Node in singly linked list 
include c header files and then use it

// A linked list Node 
struct Node { 
	int key; 
	struct Node* next; 
}; 

void deleteLast(Node** head, int key) 
{ 
	// Initialize previous of Node to be deleted 
	Node* x = NULL; 

	// Start from head and find the Node to be 
	// deleted 
	Node* temp = *head; 
  	Node* prev = NULL;
    Node* x_prev = NULL;
	while (temp) { 
		// If we found the key, update xv 
		if (temp->key == key)
        {
			x = temp;
          	x_prev = prev;
        }
		prev = temp;
		temp = temp->next; 
	} 
	// key occurs at-least once 
	if (x_prev != NULL) 
    { 
      printf("temp: %d %d", x->key, x_prev->key);
      x_prev->next = x->next;
    }
    else
    {
      printf("temp: %d", x->key);
      *head = x->next;
    }
 	delete x; 
} 

/* Utility function to create a new node with 
given key */
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->next = NULL; 
	return temp; 
} 

// This function prints contents of linked list 
// starting from the given Node 
void printList(struct Node* node) 
{ 
	while (node != NULL) { 
		printf(" %d ", node->key); 
		node = node->next; 
	} 
} 

/* Drier program to test above functions*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = newNode(1); 
	head->next = newNode(2); 
	head->next->next = newNode(3); 
	head->next->next->next = newNode(5); 
	head->next->next->next->next = newNode(2); 
	head->next->next->next->next->next = newNode(10); 

	puts("Created Linked List: "); 
	printList(head); 
	deleteLast(&head, 1); 
	puts("\nLinked List after Deletion of 1: "); 
	printList(head); 
	return 0; 
} 

