#include <stdio.h>
#define MAX 2147483647
#define MIN -2147483648

int main()
{
	int num=3;
	int b =2;
	
	int const *a;
	int * const p = &b;
	char *c;
	a = &num;
	c = &num;
	//(*a)++; //illegal
	// p = &a; //illegal
	*p =678;

	printf("%ld %ld\n",a,++a);
	printf("%ld %ld\n",c,++c);
}