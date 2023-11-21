#include <stdio.h>

int main()
{
	int a  = -2;
	// negative numbers are represented using 2's compliment.
	// 2 		     - 0000 0000 0000 0010
	// Compliment it - 1111 1111 1111 1101
	// Add 1         - 1111 1111 1111 1110                   
	printf("0x%4X\n",a);

	int b  = -3;
	// negative numbers are represented using 2's compliment.
	// 2 		     - 0000 0000 0000 0011
	// Compliment it - 1111 1111 1111 1100
	// Add 1         - 1111 1111 1111 1101                   
	printf("0x%4X\n",b);

	// When we do a right shift, sign bit stay setq always
	// other bits moves to the right side including signed bit.
	a = a>>2;
	b = b>>2;
	printf("0x%4X, %d \n",a,a);
	printf("0x%4X, %d\n",b,b);

	// When we do a left shift, all bits moves to the left side including signed bit.
	a = -2, b=-3;
	a = a<<2;
	b = b<<2;
	printf("0x%4X, %d \n",a,a);
	printf("0x%4X, %d\n",b,b);

	a = 0x80010000;
	for(int i=0;i<20;i++)
	{
		printf("0x%4X, %d \n",a,a);
			a = a>>1;
	}
	printf("\n\n");

	a = -77;
	for(int i=0;i<40;i++)
	{
		printf("0x%04X, %d \n",a,a);
			a = a<<1;
	}
	return 0;
}