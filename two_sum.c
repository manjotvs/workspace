#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printArr(int* sortArr, int sortArraySize)
{

    printf("Result(%d):",sortArraySize);
    for(int i=0;i<sortArraySize; i++)
    {
        printf(" %d", sortArr[i] );
        //free(sortArr[i]);
    }
    printf("\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *indices = (int*)malloc(sizeof(int)*2);
    int flag = 1;
    if(indices == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 2;
    for(int i = 0; i < numsSize && flag == 1; i++)
    {
        for(int j = i+1; j< numsSize; j++)
        {
            if((nums[i]+nums[j]) == target)
            {
                indices[0] = i;
                indices[1] = j;
                flag = 0;
                break;
            }
        }
    }
    return indices;
}
int main()
{
    int arr[] = {2,7,11,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int returnSize;
    int *result;
    int target = 9;
    result = twoSum(arr, size, target, &returnSize );
    printArr(result, returnSize);
    return 0;
}


