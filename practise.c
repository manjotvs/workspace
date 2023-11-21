#include<stdio.h>
#define SET_BIT(n,k)(n | (0x1<<(k-1)))
#define CLEAR_BIT(n,k)(n & (~(0x1<<(k-1))))
#define TOGGLE_BIT(n,k)(n ^ (0x1<<(k-1)))
int main()
{
	int n = 0xFFFF0000;

	printf("0x%X\n", SET_BIT(n,2));
	printf("0x%X\n", SET_BIT(n,10));
	printf("0x%X\n", CLEAR_BIT(n,32));
	printf("0x%X\n", CLEAR_BIT(n,24));
	printf("0x%X\n", TOGGLE_BIT(n,2));
	printf("0x%X\n", TOGGLE_BIT(n,32));

}