// Count number of set bits and return their positions
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkBits(uint32_t n) 
{
	int count = 0;
    printf("Postions of all the set bits: \n");
	while(n)
	{
        printf("%d ",(int)log2(n & (~(n-1))));
		n &= (n-1);
		count+=1;
	}
    printf("\n");
    return count;
}

#define SIZE (sizeof(uint32_t) * 8)
int hammingWeight(uint32_t n) {
    int num =0;
    uint32_t mask = 0x1;
    int i;
    for( i =0;i<SIZE;i++)
    {
        num += (0x1 && (n& mask));
        mask <<=1; 
    }
    return num;
}

int main()
{
    int a = 1234;
    char *arr;
    printf("Number of set bits: %d",checkBits(a));
}