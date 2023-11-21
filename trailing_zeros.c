#include <stdio.h>
#include <stdlib.h>

unsigned long long int cal_fact(char n)
{
	printf("N: %d\n",n );
	if(n<=0)
		return 1;
	return(cal_fact(n-1) * n);
}

int main()
{
	unsigned long long int fact=0;
	char n =20;
	fact = cal_fact(n);
	printf("Factorial of %d is %ld\n",n , fact);
	char trailing_spaces=0;

	while(fact % 10 ==0)
	{
		fact = fact/10;
		trailing_spaces++;
	}
	printf("Trailing spaces are %d\n", trailing_spaces );

	return 0;
}