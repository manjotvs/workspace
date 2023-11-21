#include <stddef.h>
#include <stdlib.h>
//#include <string.h>
#include <stdio.h>

void* memset_a(void* dest, uint8_t val, size_t size)
{ 
	uint8_t *d = (uint8_t*)dest;
	if(d != NULL)
	{	
		while(size--)
		{
			*d++ = val;
		}
	}
	return dest;
}

void* memcpy_a(void *dest, const void *src, size_t size)
{
	//Optimization
	if (size == 0 || dest == src)		/* nothing to do */
		return dest;
	unsigned char* d = (unsigned char*) dest;
	const unsigned char* s = (const unsigned char*) src;
	if(d && s)
	{
		while(size--)
		{
			*d++ = *s++;
		}
	}
	return dest;
}

void* memmove_a(void *dest, const void *src, size_t size)
{
	//Optimization
	if (size == 0 || dest == src)		/* nothing to do */
		return dest;
	unsigned char* d = (unsigned char*) dest;
	const unsigned char* s = (const unsigned char*) src;
	if(d && s)
	{
		char chg = 1;
		if(d>s)
		{
			chg = -1;
			d = dest + (size-1);
			s = src + (size -1);
		}
		while(size--)
		{
			*d = *s;
			d+= chg;
			s+= chg;
		}
	}
	//d[size]
	return dest;
}

int memcmp_a(const void *dest, const void *src, size_t size)
{
	//Optimization
	if (size == 0)		/* nothing to do */
		return 0;
	
	const unsigned char* d = (unsigned char*) dest;
	const unsigned char* s = (const unsigned char*) src;
	if(d && s)
	{
		while(size--)
		{
			if(*d != *s)
			{
				printf("hi\n");
				return *s-*d;
			}
			s++;
			d++;
		}
	}
	return 0;
}


int main()
{
	int size = 10;
	char str[] = "HELLO WORLD";
	char *a  = (char*)malloc(sizeof(char)*size);
	char *b = (char*)malloc(sizeof(char)*size);
	memset_a((void*)a, 0x10, sizeof(int)*size);
	memcpy_a((void*)b, (void*)str, sizeof(char)*size);
	memset_a((void*)a, 'a', sizeof(char)*size);
	memmove_a((void*)b , (void*)b+5, sizeof(char)*10);
	printf("Allocated array values:-\n");
	while(size--)
	{
		printf("Addr(%lu): %c\n",b,*b);
		b++;
	}
	//free(a);
	//free(b);

	char val1[] = "ABCDEFAHIJKLMNOPQRSTUVWXYZ";
	char val2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	printf("Ret: %d\n",memcmp_a(val1, val2, sizeof(val1)));
	return 0;
}
































