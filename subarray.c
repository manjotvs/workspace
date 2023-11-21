#include <stdio.h>
#define MAX(a,b) ((a > b)?a:b)

void subarray(char *ptr, char size)
{
	char sum = *(ptr);
	char prev_sum = *(ptr);
	char min = 0;
	char max = 0;
	char s = 0;
	for(int i = 1; i < size; i++)
	{
		sum = MAX(*(ptr+i), (sum + *(ptr+i)));
		if(sum < 0)
		{
			s = i+1;;
		}
		if(prev_sum < sum)
		{
			prev_sum = sum;
			max = i;
			min =s;
		}
	}
	printf("Final Selected Indexes(%d:%d)-> %d\n",min, max, prev_sum);

}

int main()
{
	char arr[] = {-2,1,-3,4,-5,-1,-3,-14,};
	char size = sizeof(arr)/sizeof(arr[0]);
	subarray(arr, size);
	return 0;
}