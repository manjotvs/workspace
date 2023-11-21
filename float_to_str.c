#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void reverse_str(char *val, char l)
{
	int i = 0;
	while(i<l)
	{
		*(val+i) = *(val+i) ^ *(val+l);
		*(val+l) = *(val+i) ^ *(val+l);
		*(val+i) = *(val+i) ^ *(val+l);
		i++;
		l--;
	}
}

int convert(int val, int places, char *str)
{
	int i = 0;
	while(val)
	{
		
		*(str+i) = '0' + (val %10);
		//printf("C: %c\n", *(str+i));
		val /= 10;
		i++;
	}

	while(i < places)
		*(str+i++) = '0';

	*(str+i) = '\0'; 
	reverse_str(str, i-1);
	//printf("rev: %s\n", str);
	return i;
}

void convertToStr(double val, char place, char *str)
{
	// Lets convert the integer part first
	int X;
	int i = 0;
	int j = 0;
	if(val < 0.0 )
	{
		val = -val;
		//printf("negative value after abs: %lf \n",val);
		str[0] = '-';
		j++;
	}
	X = (int)val;
	//printf("val : %d\n",X );
	i = convert(X,0,(str+j));


	// Decimal part
	if(place)
	{
		str[i+j] = '.';
		j++;
		//printf("J: %d\n",j );
		//https://www.geeksforgeeks.org/power-function-cc/
		double Y = ((val - (double)X) * pow(10,place)) + 0.5;
		i = convert((int)Y,place,str+i+j);
		//printf("Val after decimal: %lf\n", Y);

	}


}


int main()
{
	double n = -3.0027;
	char places = 7;
	char str[50];

	convertToStr(n, places, str);
	printf("Float number %s\n",str);
	return 0;
}