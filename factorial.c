#include <stdio.h>

long long unsigned int fact(long long unsigned int n)
{
	if(n==0)
		return 1;
	return (n *fact(n-1));
}


int trailingZeroes(int n) 
{
	if (n < 0)
		return -1;
 
	int count = 0;
	for (long i = 5; n / i >= 1; i *= 5) {
		printf("%d\n",i );
		count += n / i;
	}
 
	return count;
}

int main()
{
	int n=100;
	printf("Factorial of %d is %llu\n",n, fact(n));
	printf("Trailing zeros of %d is %d\n",n, trailingZeroes(n));
	return 0;
}