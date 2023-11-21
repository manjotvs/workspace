#include <stdio.h>
#include <stdint.h>

int hammingWeight1(uint32_t n) 
{
	int count = 0;
	while(n)
	{
		if(n%2)
			count++;
		n=n/2;
	}
    return count;
}

int hammingWeight2(uint32_t n) 
{
	int count = 0;
	int mask = 1;
	for(int i =0; i<32; i++)
	{
		if(mask & n )
		{
			printf("Pos: %d\n",mask);
			count++;
		}
		mask <<=1;
	}
    return count;
}

int hammingWeight3(uint32_t n) 
{
	int count = 0;
	while(n)
	{
		n &= (n-1);
		count+=1;
	}
    return count;
}

int fourthBit(int n)
{
	return((n&16)?1:0);
}

int main()
{
	uint32_t num = 1234;
	printf("%d\n",(uint32_t) (2 & ~(1) ));
	// int n = 37;
	// printf("%d\n",fourthBit(n));
	// printf("%d\n",hammingWeight2(num));
	return 0;
}