#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX 2147483647
#define MIN -2147483648

int myAtoi(char *s)
{
	int i=0;
	int num=0;
	int r=0;
	int flag =0;
	int pre_flag =1;
	while(s[i] != '\0')
	{
		while(s[i] == ' ' && pre_flag)
		{
			flag++;
			i++;
			if(s[i] == '\0')
				return 0;
		}
		if((s[i] == '-' || s[i] == '+') && pre_flag)
		{
			i++;
			if(s[i] == '\0')
				return 0;
		}

		pre_flag =0;
		if(((int)s[i] < (int)'0') || ((int)s[i] > (int)'9'))
		{
			break;
		}

		r =((int)s[i] - (int)'0');
		if(s[flag] == '-')
		{
			r=-r;
		}
		if((num > MAX/10) || (num == MAX/10 && r > 7)) return MAX;
		if((num < MIN/10) || (num == MIN/10 && r < -8)) return MIN;
		num = ((num*10)+r);
		i +=1;
	}
	return num;
}

void integer_to_str(int num, char *a)
{
	char len=0;
	if(num < 0)
	{
		len++;
		a[0] = '-';
		num=abs(num);
	}
	int temp = num;
	while(temp)
	{
		printf("n: %c\n", ((num%10) + 48));
		temp = temp /10;
		len++;
	}
	int i =len-1;
	while(num)
	{
		a[i--] = ((num%10) + 48);
		num = num /10;
	}
	a[len] = '\0';
	printf("len of string is: %d\n",len);
}


int main()
{
	char str[]= "0-1";
	printf("Integer: %d\n",myAtoi(str));
	//strcpy(str, "123abcde");
	//printf("Integer: %d\n",str_to_integer(str));
	// integer_to_str(-12345,str);
	// printf("String: %s\n",str);
	return 0;
}