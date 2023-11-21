#include <stdio.h>
char steps_way_1(unsigned int n)
{
	if(n < 2)
	{
		return n;
	}
	//unsigned int r[1000];
	char a = 0;
	char b = 1;
	char temp;
	for(int i=1; i <= n; i++)
	{

		temp = a+b;
		a=b;
		b = temp;
		//r[i] = r[i - 1] + r[i - 2];
		//printf("%d->%d\n",i,r[i] );
	}
	return temp;
}

char steps_way_2(unsigned int n)
{
	if(n <= 1)
	{
		return 1;
	}
	
	return((steps_way_2(n-2) + steps_way_2(n-1)));
}



int main()
{
	unsigned int n = 4;
	printf("Number of ways to take %d steps are %d\n",n, steps_way_2(n));
	return 0;
}