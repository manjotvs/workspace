#include <stdio.h>
#include<stdlib.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize)
{
    *returnSize = ++num;
    int *arr = malloc(sizeof(int)*(num));
    int i =0;
    int count = 0;
    while(i <(num))
    {  
        count =0;
        int j = i;
        while(j)
        {
            j &=(j-1);
            count+=1;
        }
        arr[i] = count;
        i++;
    }
    return arr;
}




int main()
{
    int i =5;
    int returnSize;
    countBits(i, &returnSize);
    printf("size: %d\n",returnSize );
    return 0;
}