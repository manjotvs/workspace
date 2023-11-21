#include <stdio.h>

char duplicate_array(int *arr, char size)
{
	int new_size = 0,i =1 ;
	while(i < size)
	{
		if( *(arr + new_size) != *(arr + i))
		{
			new_size ++;
			*(arr + new_size) = *(arr + i);	
		}
		i++;
	}
	return new_size;
}

int main()
{
	int a[] ={ 1,2,3,3,3,3,4,5,6,7,8,9,10,11,12,13,14,15}; //
	char i =0;
	char size = sizeof(a)/sizeof(a[0]);
	size  = duplicate_array(a, size);
	printf("After removing duplicate elemets of the array follows as ");
	while(i < size)
	{
		printf("%d ", a[i++] );
	}
	printf("\n");

}