#include <stdio.h>



char find_single_number(int* nums, int numSize)
{
	char temp = nums[0];
	char i =1;
	while(i < numSize)
	{
		temp ^= nums[i];
		i++;
	} 
	return temp;   
}


int main()
{
	int arr[] = {1,1,3,2,2};
	char size = (sizeof(arr)/sizeof(arr[0]));
	printf("size: %d\n",size );
	printf("A single number is: %d\n", find_single_number(arr, size));
}
