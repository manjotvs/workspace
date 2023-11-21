#include <stdio.h>



void merge_sort( int *arr, char start, char mid, char end)
{
	char i,j,k=0;
	i = start;
	j = mid+1;
	int temp[40];
	while(( i <= mid ) && ( j <= end ))
	{
		if(arr[i] >= arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else if(arr[j] > arr[i])
		{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	while( i <= mid )
	{
		temp[k] = arr[i];
		k++;
		i++;
	}
	while( j <= end )
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
	i= 0;
	k=start;
	//printf("temp: ");
	while( i < (end-start +1))
	{
		arr[k] = temp[i];
		//printf("%d ", temp[i] );
		i++;
		k++;
	}
	//printf("\n");

}


void merge( int *arr, char start, char end )
{
	if( start < end )
	{
		char mid = ( start + end ) / 2;
		merge( arr, start, mid );
		merge( arr, mid + 1, end );
		merge_sort( arr, start, mid, end );
	}
}



int main(){
	
	int arr[] = {9,4,1,2,8,15,3,45,34,100,35,78,56,0,123,12,-1};
	char size = sizeof(arr)/sizeof(arr[0]);
	merge( arr, 0, (size - 1) );
	char i=0;
	printf("Array:");
	while(i< size)
		printf(" %d", arr[i++]);
	
	printf("\n");
	return 0;
}

/* Practise 1 */
// void merge_sort(int *arr, char start, char mid, char end)
// {
// 	char i,j,temp[end-1];
// 	printf("merge_sort(%d: %d: %d)\n",start, mid, end );
// 	i = start;
// 	j = mid +1;
// 	char index = 0;

// 	//printf("merge_sort(%d: %d: %d)\n",i, j, end );
// 	while((i<=mid) && (j<=end))
// 	{
// 		//printf("Hello\n");
// 		if(*(arr+i) <= *(arr+j))
// 		{
// 			temp[index] = *(arr+i);
// 			i++;
// 		}
// 		else
// 		{
// 			temp[index] = *(arr+j);
// 			j++;
// 		}
// 		index++;
// 	}
// 	while( i <=mid)
// 	{
// 		//printf("Hi\n");
// 		temp[index] = *(arr+i);
// 		index++;
// 		i++;
// 	}
// 	while( j <= end)
// 	{
// 		temp[index] = *(arr+j);
// 		index++;
// 		j++;
// 	}
// 	index = 0;
// 	for ( i = start; i <= end; i++)
// 	{
// 		*(arr+i) = temp[index];
// 		index++;
// 	}
// }


// void merge(int *arr, char start, char end)
// {
// 	static int i=0;
//     if(start < end)
//     {

//     //printf("Merge(%d) -> %d: %d)\n",i++ , start, end);
//         char mid = (start + end)/2;
//         merge(arr, start, mid);
//         merge(arr, mid+1, end);
//         merge_sort(arr, start, mid, end);
//     }
// }