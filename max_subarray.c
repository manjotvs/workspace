#include <stdio.h>
#include <stdlib.h>

int max(int A, int B, int C)
{
	int M = A;
	if(B > M)
		M = B;
	if(C > M)
		M = C;
	return M;
}

int maxCrossingSub(int *nums, int p, int q, int r)
{
	int lsum = 0;
	int rsum = 0;
	int i = q;
	int sum = lsum = nums[i--];
	while(i >= p)
	{
		sum+=nums[i--];
		if(lsum < sum)
			lsum = sum;
	}
	i = q+1;
	sum = rsum = nums[i++];
	while(i <= r)
	{
		sum+=nums[i++];

		if(rsum < sum)
			rsum = sum;
	}
	return (rsum+lsum);
}

int maxSubArrayRec(int *nums, int p, int r)
{
	if(p==r)
	{
		return nums[p];
	}
	int q = (p+r)/2;
	int L = maxSubArrayRec(nums,p,q);
	int R = maxSubArrayRec(nums,q+1,r);
	int C = maxCrossingSub(nums,p,q,r);
	return(max(L,R,C));
}
int maxSubArray(int* nums, int numsSize)
{
	return (maxSubArrayRec(nums, 0, numsSize-1));
}

int maxSubArrayKadaneAlgo(int* nums, int numsSize)
{
	int sum=0;
	int max_sum = nums[0];
	for(int i=0; i<numsSize; i++)
	{
		sum += nums[i];
		if(nums[i] > sum)
			sum = nums[i];
		if(max_sum < sum)
			max_sum = sum;
	}
	return max_sum;
}

int main()
{
	int nums[] = {-1,3,4,-5};
	printf("Sum: %d\n",maxSubArrayKadaneAlgo(nums, sizeof(nums)/sizeof(nums[0])));
	return 0;
}