#include <stdio.h>
#include <stddef.h>

void* memcpy(void *dest, const void *src, size_t len)
{
	char *d = (char*)dest;
	const char *s = (const char*)src;
	while(len--)
	{
		*d++ = *s++;
	}
	return dest;
}

int main()
{
	char val1[] = "hello";
	char val2[] = "hi";
	printf("Val2 value before mempcy: %s\n",val1);
	memcpy(val1, val2, 3);

	printf("Val2 value after mempcy: %s\n",val1);
	
          
    return 0; 
}