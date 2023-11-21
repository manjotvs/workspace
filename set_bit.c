#include <stdio.h>

#define CHECK_BIT(a,b) ((a>>b) & 0x1)

int main()
{
	char a=0xF0;
	printf("Bit is %d\n",CHECK_BIT(a,4));
	return 0;
}