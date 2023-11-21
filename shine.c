#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//https://leetcode.com/discuss/interview-question/502549/

int findShine1(char *arr, int len)
{
	char *table = malloc(len+1);
	memset(table,0x00,len+1);
	int count =0;
	for(int i =0;i< len;i++)
	{
		bool shine =1;
		printf("element: %d\n",arr[i]);
		for(int j=1;j<arr[i];j++)
		{
			if(table[j]==0)
				shine = 0;
		}
		table[arr[i]] = 1;
		if(shine)
			count++;
	}
	return count;
}


int findShine(char *arr, int len)
{
	int ans = 0, sum = 0, target = 0;
		
	for(int i = 1; i<= len; i++) 
	{
		sum += arr[i-1];
		target += i ; //Sum from 1 to i
		printf("s: %d, t: %d\n",sum,target);
		if(sum == target) ans++;
	}
		
	return ans;
}

int main()
{
	char A[] = { 2, 1, 3, 5, 4}; //3
	//char A[] = { 2, 3, 4, 1, 5}; //2
	//char A[] = { 5,4,3,2,1}; //1
	printf("Count: %d\n",findShine(A,sizeof(A)/sizeof(A[0])));
	return 0;
}