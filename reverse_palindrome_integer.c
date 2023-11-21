#include<stdio.h>
#include<math.h>
#define MAX 2147483647
#define MIN -2147483648
int reverse_integer(long long a)
{
	int r=0;
	char j=0;
	while(a)
	{
		j = a%10;
		a = a/10;
		if((r > MAX/10) || (r == MAX/10 && j > 7)) return 0;
		if((r < MIN/10) || (r == MIN/10 && j < 8)) return 0;
		r = ((r*10)+j);
	}
	return r;
}

int check_palindrome(int a)
{
	int temp=a;
	int r=0;
	char j=0;
	if(a == 0)
		return 1;
	else if(a>0)
	{
		while(a)
		{
			j = a%10;
			a = a/10;
			if((r > MAX/10) || (r == MAX/10 && j > 7)) return 0;
			if((r < MIN/10) || (r == MIN/10 && j < 8)) return 0;
			r = ((r*10)+j);
		}
		if(temp == r)
			return 1;
	}
	return 0;
}
int main()
{
	long long a=7463847419;
	int b= 10;
	if((a=reverse_integer(a)))
		printf("reverse_integer %d\n",a);
	else
		printf("Overflowed\n");
	if((check_palindrome(b)))
		printf("palindorme!!!\n");
	else
		printf("Not Palindrome!!!\n");
	return 0;
}