#include <stdio.h>


uint32_t reverseBits(uint32_t n) {
    
    uint32_t revNum = 0;
    uint32_t mask = 0x1;
    uint32_t rev_mask = 0x80000000;
    char i = 0;
    while(i < 32)
    {
        if(mask & n)
        {
            revNum |= rev_mask; 
        }
        mask <<= 1;
        rev_mask >>=1;
        i++;
    }
    return revNum;
}


uint32_t reverseBits1(uint32_t n) {
    
    n = (((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16));
    n = (((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8));
    n = (((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4));
    n = (((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2));
    n = (((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1));
    return n;
}


int main()
{
	int a =0x3411;

	int b = 0x0;
	char i = 16;
	while(a)
	{

	 	printf("a: 0x%02X b: 0x%02X\n",((a & 0x1)<<i),b);
	 	b |= ((a & 0x1) << (i-1)) ;
	 	a = a >> 1;
	 	i--;
	}	
	printf("Reverse Byte: 0x%02X\n",b);
	return 0;
}