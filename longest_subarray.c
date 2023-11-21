#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)



char find_longest_subrarry(int* nums, int numSize)
{
	int prev_max_sum =0 ;
	int curr_max_sum = 0;
	char min=0,max=0;
	char i =0;
	while(i < numSize)
	{
		curr_max_sum+= nums[i];
		if( nums[i] > curr_max_sum )
		{
			curr_max_sum = nums[i];
			min = i;
		}

		if( prev_max_sum < curr_max_sum )
		{
			prev_max_sum = curr_max_sum;
			max = i;
		}
		//curr_max_sum = MAX(nums[i], curr_max_sum);
		prev_max_sum = MAX(curr_max_sum, prev_max_sum);
		printf("Curr and Prev Max: %d %d\n",curr_max_sum, prev_max_sum );

		printf("Min & Max: %d %d\n",min, max );
		i++;
	} 
	return prev_max_sum;   
}


int main()
{
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	char size = (sizeof(arr)/sizeof(arr[0]));
	printf("size: %d\n",size );
	printf("Maximum sum of subarray is: %d\n", find_longest_subrarry(arr, size));
}
