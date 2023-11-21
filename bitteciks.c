#include <stdio.h>
#include <stdint.h>
#include <math.h>


int main()
{
	int n =-32;
	int a = 0x88;

	/* find the lowest bit set in a given byte */
	printf("LowestBitPosition: %f\n",log2(a&(~(a-1))));

	/* check if ith bit is set */
	int i = 4;
	printf("Particular position(%d) in num(0x%X) is (%d)\n",i,a,((a >> i) & 0x1) );
	printf("Set particular position(%d) in num(0x%X) is (0x%X)\n",i,a,(a | (0x1 << i)));
	printf("Clear Particular position(%d) in num(0x%X) is (0x%X)\n",i,a,(a & ~(0x1 << i)));

	return 0;
	/* find the sign of the number */
	printf("Sign: %d\n",-(n<0)); /* first method */

	uint32_t mask = 1 << ((sizeof(int) * 8) -1 ); /* second method using mask 8 refers to numer of bits per byte*/
	printf("Sign: %d\n",(n&mask));
	uint32_t numbits = ((sizeof(int) * 8) -1 ); /* third method using mask 8 refers to numer of bits per byte*/
	printf("Sign: %d\n",(n >> numbits));


	/* detect if two nos have opposite signs */
	a = 32;
	int b = -31;
	printf("if nos have opposite sign(True or False): %d\n",((a ^ b ) < 0));

	/* find the minimum of two nos */
	int x =2;
	int y =1;
	int r = 0;
	//r = y ^ ((x ^ y) & -(x < y)); // to find the minimum
	r = x ^ ((x ^ y) & -(x < y)); // to find the maximum
	printf("%d\n",r );

	// int n = 37;
	// printf("%d\n",fourthBit(n));
	// printf("%d\n",hammingWeight2(num));
	return 0;
}