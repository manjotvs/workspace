#include <stdio.h>
#include <stdlib.h>

void tostring(int n, char *str)
{
	char rem = 0;
	char i =0;
	char len=0;
	if(n < 0)
	{
		*(str+len++) = '-';
		n = abs(n);
	}

	int temp = n;
	while(temp)
	{
		temp =temp/10;
		len++;
	}
	for( i=len-1;n>0; i--)
	{
		rem = n %10;
		n = n /10;
		*(str+i) = rem + '0';
	}
	*(str+len) = '\0';
}

int tointeger(char *str)
{
	char i =0;
	int n=0;
	if(*(str) == '-')
		i++;
	while(*(str+i) != '\0')
	{
		n = (n * 10) + (*(str+i)- 48);
		printf("%c %d\n", *(str+i),n);
		i++;
	}
	if(*(str) == '-')
		n =-n;
	return n;
}

int main()
{
	int n = -12345;
	char str[10];
	tostring(n, str);
	printf("%s\n", str);
	n=0;
	n = tointeger(str);
	printf("%d\n", n );
}