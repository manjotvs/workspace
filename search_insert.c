#include <stdio.h>

char search_insert(char *arr, char start, char end, char k)
{
	char mid;
	if(start < end)
	{
		mid = (start + end)/2;
		if(arr[mid]== k)
			return mid;
		if(arr[mid] > k)
			return(search_insert(arr, start, mid, k));
		else
			return(search_insert(arr, mid+1, end, k));

	}
	return start;
}

int main()
{
	char arr[] = {1,2,5,8,12,56};
	char size = sizeof(arr) / sizeof(arr[0]);
	char k =0;
	char pos = search_insert(arr, 0, size -1, k);
	printf("Position at an elment[%d] is found or should be inserted: %d\n",k , pos );
	return 0;
}