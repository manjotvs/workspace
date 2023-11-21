#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint8_t power_of_2(char num)
{
	if(num == 1 || num < 0)
		return 0;

	while(num>1)
	{
		if(num % 2 != 0)
			return 0;
		num = num/2;
	}
	return 1;
}

int isPowerOfTwo(int x)
{
     // First x in the below expression is
     // for  the case when x is 0 
     return x && (!(x & (x - 1)));
}
uint8_t isPalindrome(uint32_t input) {

	uint32_t msb = log2(input);
	printf("msb: %d",msb);

	for (int i = 0; i < msb / 2; i++) {
		uint8_t left = ((1 << (msb - i)) & input) != 0 ? 1 : 0;
		uint8_t right = ((1 << i) & input) != 0 ? 1 : 0;

		if (left != right) {
			return 0;
	}
}

return 1;
}
int main()
{
	for(int i = 0;i<100;i++)
	printf("Number(%d) is power of 2: %d\n",i, isPowerOfTwo(i));
	int n = 0x700e;
	printf("Number(%d): isPalindrome(%d)\n",n,isPalindrome(n));
	return 0;
}
