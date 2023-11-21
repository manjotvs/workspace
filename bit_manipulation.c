#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define CHAR_BIT 8

// Ref link: http://graphics.stanford.edu/~seander/bithacks.html

#define SET_BIT(n,p) (n = n | (0x1 << p))
#define CLEAR_BIT(n,p) (n = n & ~(0x1 << p))
#define CHECK_BIT(n,p) !!(n&(0x1<<p))

/* check if number is power of 2*/
bool is_num_pow2(uint32_t n)
{
	return(n&&!(n&n-1));
}

/* Detect if two integers have opposite signs */
/* Note:  Cannot use multiplication because number will overflow */
bool is_opposite_signs(int m, int n )
{
	return((n*m)<0);
}

int main()
{
	char a=0x00;
	printf("Num is 0x%02X\n", SET_BIT(a,4));
	printf("Num is 0x%02X\n", SET_BIT(a,6));
	printf("Num is 0x%02X\n", CLEAR_BIT(a,4));
	printf("Bit is 0x%02X\n", CHECK_BIT(a,6));
	printf("Bit is 0x%02X\n", CHECK_BIT(a,4));

	/* Set a particular bit in register value */
	int reg = 0xFF;
	int *b = &reg;
	reg = CLEAR_BIT(*b,0);
	printf("Num is 0x%02X\n", reg);
	reg = CLEAR_BIT(*b,1);
	printf("Num is 0x%02X\n", reg);


	uint32_t n = 2048;
	/* check if number is power of 2*/
	printf("Check if the number(%d) is power of 2(yes(1) or no(0)): %d\n", n, is_num_pow2(n));
	n = 0;
	printf("Check if the number(%d) is power of 2(yes(1) or no(0)): %d\n", n, is_num_pow2(n));
	int m = 2147483647;
	n = 2147483647;
	/* Detect if two integers have opposite signs */
	printf("Check if the numbers(%d, %d) are having opposite signs(yes(1) or no(0)): %d\n", m, n, is_opposite_signs(m,n));

	// Compute the minimum (min) or maximum (max) of two integers without branching



	/* calculate the absolute value */ 
	reg = -1234;
	uint32_t result = 0;
	int const mask = reg >> ((sizeof(int) * 8) - 1);
	printf("Mask: 0x%X\n",mask);
	result = (reg+mask)^mask;
	printf("Absolute Number(%d): %d %d\n",reg,result,abs(reg));



	return 0;
}