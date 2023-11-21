#include <stdio.h>



void rotate(int* nums, int numSize, int k)
{
	while(k--)
	{
		char tempSize = numSize-1;
		char temp = nums[numSize-1];
		for(char i = tempSize; i > 0; i--)
		{
			nums[i] = nums[i-1];
		}
		nums[0] = temp;
	}    

}


int main()
{
	int arr[] = {1,-100,3,99};
	int k = 2; // Number of rotations
	char size = (sizeof(arr)/sizeof(arr[0]));
	printf("size: %d\n",size );
	rotate(arr, size, k);
	char i=0;
	while(i < size)
	{
		printf("arr[%d]: %d\n", i, arr[i]);
		i++;
	}

}



































// char temp;
//     char i;
    
//     printf("Size: %d\n", numSize);
//     while(k--)
//     {
//     	i = numSize -1;
//     	temp = *(nums + i);
//     	printf("Temp: %d\n",temp);
//     	while(i)
// 	    {
// 	    	*(nums + i) = *(nums+ i -1);
// 	    	i--;
// 	    }
// 	    *nums = temp;
// 	}