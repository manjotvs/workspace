#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DEBUG
/* number of times through the loop */
extern int counter;

/* routine to increment the counter */  void inc_counter(void);
/* cannot extern the static variable defined in another file */
extern int a;

void bubbleSortArray(int *nums, int numsSize)
{
    for(int i=0; i < numsSize; i++)
    {
        bool optimized = false;
        for(int j=0; j<numsSize-1;j++)
        {
            if(nums[j] > nums[j+1])
            {
                nums[j] = nums[j+1] ^ nums[j];
                nums[j+1] = nums[j+1] ^ nums[j];
                nums[j] = nums[j+1] ^ nums[j];
            }
        }
    }  
}

void optimizedBubbleSortArray(int *nums, int numsSize)
{
    bool optimized = false;
    for(int i=0; i < numsSize; i++)
    {
        bool optimized = false;
        for(int j=0; j<numsSize-1;j++)
        {
            if(nums[j] > nums[j+1])
            {
                nums[j] = nums[j+1] ^ nums[j];
                nums[j+1] = nums[j+1] ^ nums[j];
                nums[j] = nums[j+1] ^ nums[j];
                optimized = true;
            }
        }
        if(optimized == false)
            break;
    }  
}

void insertionSort(int *a, int numsSize)
{
	int i,k;
	int temp;
    for(int j = 1; j < numsSize; j++ )
    {
        i = j -1;
        temp = a[j];
        while((a[i] > temp ) && (i >=0))
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = temp;
    #ifdef DEBUG
        for(k=0; k<numsSize; k++)
	    {
	        printf("%d ",a[k]);
	    }
	    printf("\n");
	#endif
    }
 
}

/*
Worst complexity: n*log(n)
Average complexity: n*log(n)
Best complexity: n*log(n)
Space complexity: n
Method: Merging
Stable: Yes
*/
void mergeConquerCombine(int *arr, int beg, int mid, int end)
{
    int i = beg;
    int j = mid +1;
    int temp_arr[end+1];
    #ifdef DEBUG
    printf("beg: %d end: %d mid: %d\n",beg, end,mid+1 );
    #endif
    int k =beg;
    while(k<=end)
    {
    	if(i>mid)
    	{
    		temp_arr[k++] = arr[j++];
    	}
    	else if(j>end)
    	{
    		temp_arr[k++] = arr[i++];
    	}
        else if(arr[i] > arr[j])
        {
        	temp_arr[k++] = arr[j++];
        }
        else
        {
        	temp_arr[k++] = arr[i++];
        }
    }
    #ifdef DEBUG
    printf("i: %d j: %d\n",i, j );
    #endif
	for( k=beg; k<=end; k++)
	{
		#ifdef DEBUG
	    printf("%d ",temp_arr[k]);
	    #endif
		arr[k] = temp_arr[k];
	}
	#ifdef DEBUG
	printf("\n");
	#endif
}


void mergeSortDivide(int *arr, int beg, int end)
{
    if(beg < end)
    {
	    int mid =(beg+end)/2;
	    mergeSortDivide(arr, beg, mid);
	    mergeSortDivide(arr, mid+1, end);
	    mergeConquerCombine(arr, beg, mid, end);
	}
}

void quickSwap(int *a, int *b)
{
	if(*a == *b)
		return;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int quickPartition(int *arr, int start, int end)
{
	int i = start+1;
	int pivot = arr[start];
	int j;
	for(j = start+1; j<=end; j++)
	{
		if(arr[j]<pivot)
		{
			quickSwap(&arr[i],&arr[j]);
			i++;
		}
	}
	quickSwap(&arr[i-1],&arr[start]);
	return (i-1);
}

void quickSort(int *arr, int start, int end)
{
	if(start < end)
	{
		int pv = quickPartition(arr, start, end);
		quickSort(arr, start, pv-1);
		quickSort(arr, pv+1, end);
	}
}

int main() 
{

int index; /* loop index */
	counter++;// legal operation
for (index = 0; index < 10; index++) 
	inc_counter();
printf("Counter is %d \n", counter);
printf("a: %d\n",a );

//int arr[] = {5,4,10,1,6,2};
// int arr[] = {47,47,72,47,72,47,79,47,12,92,13,47,47,83,33,15,18,47,47,47,47,64,47,65,
// 	47,47,47,47,70,47,47,55,47,15,60,47,47,47,47,47,46,30,58,59,47,47,47,47,47,90,64,37,
// 	20,47,100,84,47,47,47,47,47,89,47,36,47,60,47,18,47,34,47,47,47,47,47,22,47,54,30,11,
// 	47,47,86,47,55,40,49,34,19,67,16,47,36,47,41,19,80,47,47,27};
//int arr[] = {2,2,1,1,1,2,2}; //7
//int arr[] = {3,2,3};
//insertionSort(arr, 7);
int arr[6] = {60,47,92,13,47,47}; //7
int numsSize = sizeof(arr)/sizeof(arr[0]);
printf("Size: %d\n",numsSize );
//mergeSortDivide(arr, 0, numsSize-1);
quickSort(arr, 0, numsSize-1);
#ifdef DEBUG
for(int k=0; k<numsSize; k++)
{
    printf("%d ",arr[k]);
}
printf("\n");
#endif

return (0); 
}