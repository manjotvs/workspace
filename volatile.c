#include<stdio.h>

int main() // main class
{
	volatile const int a = 134 ;
	//const int a = 134 ;
	int *p = (int*)&a;
	printf("a: %d\n",a);
	//a = 135;
	*p = 200;
	printf("a: %d\n",a);
	return 0 ;
}