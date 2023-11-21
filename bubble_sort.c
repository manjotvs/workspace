#include <stdio.h>

// Time Complexity = O(n(n+1)/2) = O(n^2)
void bubble_sort(char *arr, char size)
{
	char i,j,temp;
	for(i = 0; i< size; i++)
	{
		for (j = 0; j < size-i; j++)
		{
			if(*(arr+j) > *(arr+j+1))
			{
				temp = *(arr+j);
				*(arr+j) = *(arr+j+1);
				*(arr+j+1) = temp;
			}
		}
	}
}

int main()
{
	char arr[] = {12,34,35,39,45,67,78};
	char size = sizeof(arr) - sizeof(arr[0]);
	bubble_sort(arr, size);
	int i =0;
	while(i < size)
		printf("%d ", arr[i++]);
	printf("\n");
	return 0;
}

