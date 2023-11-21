#include <stdio.h>

char find_palindrome(unsigned int n)
{
	unsigned int rev_no = 0;
	while(rev_no < n)
	{
		rev_no = ((rev_no * 10) + (n %10));
		printf("rev_no: %d\n", rev_no);
		if((rev_no/10) == n || rev_no == n)
			return 1;
		if(rev_no > n)
			return 0;
		n = n /10;
	}
	return 0;
}

int main()
{
	unsigned int n = 12321;
	if(find_palindrome(n))
	{
		printf("It is a palindrome integer\n");
	}
	else
		printf("It is not a palindrome integer\n");
	return 0;
}