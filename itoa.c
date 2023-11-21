#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define <limits.h>

void swap_str_values(char *str)
{
	int len = strlen(str);
	int i = 0;
	int j = len-1;
	char temp;
	while(i < j)
	{
		temp = str[i] ^ str[j];
		str[j] = temp ^ str[j];
		str[i] = temp ^ str[i];
		i++;
		j--;
	}
	str[len] = '\0';
}

void itoa(int value, char *str, int base)
{
	//memset(buffer, 0x)
	char base_number = '0';
	char base_alphabet = 'A';
	int rem = 0;
	char neg=0;
	/* Handling hexadecimal( Base 16 ) */
	int i = 0;
	if(value == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	if(value < 0 && base == 10)
	{
		value = -value;
		neg =1;
	}
	while(value)
	{
		rem = value % base;
		if(rem > 9)
		{
			*(str + i) =  ( base_alphabet + (rem - 10));
		}
		else
		{
			*(str + i) =  ( base_number + rem );
		}
		value /= base;
		i++;
	}
	if(neg)
	{
		*(str + i) = '-';
		i++;
	}
	*(str + i) = '\0';
	swap_str_values(str);
	
}

int main()
{
	int value = -1567;
	char buffer[50];
	itoa(value, buffer, 16);
	printf("Hexadecimal value is %s\n", buffer);
	itoa(ULONG_MAX, buffer, 10);
	printf("Decimal value is %s\n", buffer);
	itoa(value, buffer, 2);
	printf("Decimal value is %s\n", buffer);
	itoa(value, buffer, 8);
	printf("Decimal value is %s\n", buffer);

	return 0;
}