#include<stdio.h> 

/* Dangling pointer pointing to a memory location that has been freed or deleted */

int *fun() 
{ 
    // x is local variable and goes out of 
    // scope after an execution of fun() is 
    // over. 
    int x = 5; 
    //static int x = 5; 
  
    return &x; 
} 
  
// Driver Code 
int main() 
{ 
    int *p = fun(); 
    fflush(stdin); 
  
    // p points to something which is not 
    // valid anymore 
    printf("%d\n", *p); 
    return 0; 
} 