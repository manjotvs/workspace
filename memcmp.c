#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define own

#ifdef own
int memcmp(void *ptr1, const void *ptr2, size_t len)
{
	uint8_t *p1 = (uint8_t*)ptr1;
	uint8_t *p2 = (uint8_t*)ptr2;

	while(len--)
	{
		if(*p1 != *p2)
			return (*p1 - *p2); 
		p1++;
		p2++;
	}
	return 0;
} 

#else
#include <string.h>
#endif

int main()
{
	char val1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char val2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	printf("Ret: %d\n",memcmp(val1, val2, sizeof(val1)));

	
	return 0;
}