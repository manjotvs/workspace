#include <stdio.h>
#include <stdlib.h>

void print_arr(char *arr, char size)
{
	char i  = 0;
	printf("Array:");
	while(i < size)
	{
		printf(" %d", *(arr+i));
		i++;
	}
	printf("\n");
}

char quick_partition(char *arr, char beg, char end)
{
	char loc, temp, flag;
	loc = end;
	flag = 0;
	while(flag != 1)
	{
		while(arr[beg] <= arr[loc] && beg != loc)
		{
			beg ++;
		}
		if(beg == loc )
		{
			flag = 1;
			return loc;
		}
		else
		{
			temp = arr[loc];
			arr[loc] = arr[beg];
			arr[beg] = temp;
			loc = beg;
		}
		while(arr[end] >= arr[loc] && end != loc)
		{
			end --;
		}
		if(end == loc )
		{
			flag = 1;
			return loc;
		}
		else
		{
			temp = arr[loc];
			arr[loc] = arr[end];
			arr[end] = temp;
		}

	}
	return loc;

}

void quick_sort(char *ptr, char beg, char end)
{
	char loc;
	if(beg < end)
	{
		loc = quick_partition(ptr, beg, end);
		printf("LOC: %d\n", loc );
		//print_arr(ptr, end+1);
		quick_sort(ptr, beg, loc-1);
		quick_sort(ptr, loc+1, end);
	}
}



int main()
{	
	char arr[] = {23,12,15,25,1,19};
	char size = (sizeof(arr)- sizeof(arr[0]));
	print_arr(arr, size);
	quick_sort(arr, 0, size-1);
	print_arr(arr, size);
	return 0;

}