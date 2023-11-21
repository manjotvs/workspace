#include <stdio.h>
#include <stdint.h>

int main()
{
	uint8_t a = 0xA3;

	a = (((a>>4)&0x0F)|((a<<4)&0xF0));

	a = (((a>>2)&0x33)|((a<<2)&0xCC));

	a = (((a>>1)&0x55)|((a<<1)&0xAA));

	printf("Value after reverse: 0x%2X\n",a );
}