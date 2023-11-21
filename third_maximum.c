#include <stdio.h>

/* First practise */
int thirdMax(int *arr, int size)
{
	long max[3];
	printf("Size: %d\n",size );
	max[0] = LONG_MIN;
	max[1] = LONG_MIN;
	max[2] = LONG_MIN;
	char i =0;
	while(i < size)
	{
		if(max[0] < arr[i])
		{
		//printf("Hi\n");
			max[2] = max[1];
			max[1] = max[0];
			max[0] = arr[i];
		}
		else if(max[1] < arr[i])
		{
			//printf("hello: %d\n", arr[i]);
			if(max[0] == arr[i])
			{
				i++;
				continue;
			}
			max[2] = max[1];
			max[1] = arr[i];
		}
		else if(max[2] < arr[i])
		{
			if(max[1] == arr[i])
			{
				i++;
				continue;
			}
			max[2] = arr[i];
		}
		i++;
	}
	printf("Max: %d %d %d\n", max[0],max[1], max[2] );
	
   return (max[2]>LONG_MIN)?max[2]:max[0];
}

/* Second practise */
int find_max_number( int *arr, int size)
{
	char i = 1;
	int max[3];
	/* If any max number matches the array element just continue without even comparing */
	max[0] = max[1] = max[2] = arr[0];
	for( ; i < size; i++ )
	{	
		if( ( max[0] == arr[i] ) || ( max[1] == arr[i] ) || ( max[2] == arr[i] ) )
			continue;
		if( arr[i] > max[0] )
		{
			max[2] = max[1];
			max[1] = max[0];
			max[0] = arr[i];
		}
		else if( arr[i] > max[1] )
		{
			max[2] = max[1];
			max[1] = arr[i];
		}
		else if( arr[i] > max[2] )
		{
			max[2] = arr[i];
		}
	}
	/* If third largest elements is not present then return the maximum */
	/* arr[] = 41, 52, 52
	`* max[0] = max[1] = max[2] = arr[0] = 41;
	 * after the first loop 
	 * max[0] = 52 & max[1] = max[2] = 41
	 * so no third largest element 
	 */
	if( max[1] == max[2] )
	{
		return max[0];
	}
	printf("Maximum numbers: %d %d %d\n", max[0], max[1], max[2] );
	return max[2];
}


int main()
{
	//int arr[] = {5,5,3,10,15,2,4,5,1,1,0,-4,-5,4,1,-6,5,5};
	//int arr[] = {1,2};
	int arr[] = {1,2,2};

	printf("Third maximum number: %d\n",thirdMax(arr, sizeof(arr)/sizeof(arr[0])));
	printf("Third maximum number: %d\n",find_max_number(arr, sizeof(arr)/sizeof(arr[0])));
	
	// Another Method
	// Sort the array in descending order
	// then traverse thru the list to find the third max element
	return 0;
}