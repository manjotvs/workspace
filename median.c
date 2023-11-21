/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
double findMedianSortedArrays1(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int totalSize = nums1Size + nums2Size;
    int nums[totalSize];
    int nth = totalSize/2;

 
    int i =0, j=0, k=0;
    while(i < nums1Size && j < nums2Size)
    {
        if(nums1[i] > nums2[j])
        {
            nums[k] = nums2[j];
            j++;
        }
        else
        {
            nums[k] = nums1[i];
            i++;
        }
        k++;
    }
    while(i < nums1Size)
    {
        nums[k] = nums1[i];
        i++;
        k++;
    }
    while(j < nums2Size)
    {
        nums[k] = nums2[j];
        j++;
        k++;
    }
    if(((totalSize % 2) == 0) && (totalSize > 1) )
    {
        return (double) ( ((double)nums[nth-1] + nums[nth]) / 2 );
    }
    else
    {
        return (double) ((double)nums[nth]);
    }

}

// Runtime: 12 ms, faster than 87.32% of C online submissions for Median of Two Sorted Arrays.
// Memory Usage: 7.8 MB, less than 55.56% of C online submissions for Median of Two Sorted Arrays.


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int totalSize = nums1Size + nums2Size;
    int nums[totalSize];
    int nth = totalSize/2;

 
    int i =0, j=0, k=0;
    while(i < nums1Size && j < nums2Size && k <= nth)
    {
        if(nums1[i] > nums2[j])
        {
            nums[k] = nums2[j];
            j++;
        }
        else
        {
            nums[k] = nums1[i];
            i++;
        }
        k++;
    }
    while(i < nums1Size && k <= nth)
    {
        nums[k] = nums1[i];
        i++;
        k++;
    }
    while(j < nums2Size && k <= nth)
    {
        nums[k] = nums2[j];
        j++;
        k++;
    }
    if(((totalSize % 2) == 0) && (totalSize > 1) )
    {
        return (double) ( ((double)nums[nth-1] + nums[nth]) / 2 );
    }
    else
    {
        return (double) ((double)nums[nth]);
    }

}

// Runtime: 16 ms, faster than 63.22% of C online submissions for Median of Two Sorted Arrays.
// Memory Usage: 7.8 MB, less than 55.56% of C online submissions for Median of Two Sorted Arrays.
int main()
{
    // int nums1[] = {3,4,5};
    // int nums2[] = {2,9};

    // //Input
    int nums1[] = {3};
    int nums2[] = {-2,-1};
     // output -1

    // int nums1[] = {1,3};
    // int nums2[] = {2};

    // int nums1[] = {1,2};
    // int nums2[] = {3,4};
    // output 2.5

    
    printf("%f\n",findMedianSortedArrays(nums1,1,nums2,2));
    return 0;
}


