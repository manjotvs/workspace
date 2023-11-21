#include <stdio.h>


void main()
{
	char a = 0x34;
	char r,i=0;
	while(i < 8)
	{
		printf("a:0x%02X\n", a);
		r = (r << 0x1) | ((a >> i) & 0x1);
		//a = a >> 1;
		i++;
		printf("0x%02X\n",r);
	}
	printf("Reverse value: 0x%02X\n",r );
}