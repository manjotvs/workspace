#include <stdio.h>


char binary_search(char *arr, char start, char end, char k)
{
	static char i=0;
	char mid;
	printf("Iteration time(%d) - Start[%d] - End[%d]\n",i++, start, end );
	if(start <= end)
	{
		mid = ((start + end)/2);
		printf("arr[%d]: %d\n",mid, *(arr+mid));
		if(*(arr+mid) == k)
			return mid;
		else if(*(arr+mid) < k)
			return(binary_search(arr, mid+1, end, k));
		else
			return(binary_search(arr, start, mid-1, k));
	}
	return -1;

}

int main()
{
	char arr[] = {12,34,35,39,45,67,78};

	printf("Found an element at pos(%d)!\n",binary_search(arr, 0, (sizeof(arr) - sizeof(arr[0])), 10));
	return 0;
}

