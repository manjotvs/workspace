#include <stdio.h>

char length(char *arr)
{
	char i=0, j=0;
	while(arr[i] != '\0')
	{
		if(arr[i] == ' ')
			j=0;
		else
		{
			//arr[j] = arr[i];
			j++;
		}
		i++;

	}
	
	return j;
}

int main()
{
	char arr1[] = "HELLO World";
	char arr2[] = "Welcome to my system!";
	char len = length(arr2);
	printf("Length of last element: %d\n",len );
	return 0;
}