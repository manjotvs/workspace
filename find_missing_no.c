#include <stdio.h>

char find_missing_no(int *arr, char size)
{
	char missing_no = size;
	char i = 0;
	while(i < size)
	{
		printf("Missing val %d\n",missing_no );
		missing_no ^= i ^ arr[i];
		i++;
	}
	return missing_no;
}

int main()
{
	int a[] ={0,1,4,3,5,6}; //
	char missing_no =0;
	char size = sizeof(a)/sizeof(a[0]);
	printf("size: %d\n", size );
	missing_no  = find_missing_no(a, size);
	printf("Missing Number is %d\n", missing_no );


}