#include <stdio.h>

void reverse_array(int *arr, char size)
{
	int temp;
	for(int i =0, j=size-1; i < size/2; i++,j--)
	{
		temp = *(arr+i);
		*(arr+i) = *(arr+j);
		*(arr+j) = temp;
	}
}

int main()
{
	int a[] ={ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	char i =0;
	char size = sizeof(a)/sizeof(a[0]);
	reverse_array(a, size);
	printf("Reverse elemets of the array follows as ");
	while(i < size)
	{
		printf("%d ", a[i++] );
	}
	printf("\n");

}