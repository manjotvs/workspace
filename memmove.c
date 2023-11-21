#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

typedef struct
{
     char Data1;
     //3-Bytes Added here.
     int Data2;
     unsigned short Data3;
     char Data4;
     //1-byte Added here.

}__attribute__((aligned(2)))sSampleStruct;


// First Method
// void *memmove(void *dest, const void *src, size_t len)
// {
// 	char *temp = malloc(len);
// 	memcpy(temp,src,len);
// 	char* d = (char*)dest;
// 	const char* s = (const char*)temp;
// 	while(len--)
// 	{
// 		*d++ = *s++;
// 	}
// 	return dest;
// } 

//#define own

#ifdef own
// Second Method
void *memmove(void *dest, const void *src, size_t len)
{
	
	const char *s = (const char*)src;
	char *d =  (char*)dest;
	char sign=0;
	printf("Addresses %lu %lu\n",s,d );
	if(s > d)
	{
		sign = 1;
	}
	else
	{
		s+=len-1;
		d+=len-1;
		sign = -1;
	}
	while(len--  && sign)
	{
		*d = *s;
		d+= sign;
		s+= sign;
		//len--;
	}
	return dest;
} 

#else
#include <string.h>
#endif

int main()
{
	// sSampleStruct sa;
	// sSampleStruct sb;
	// printf("Size: %lu\n",sizeof(sSampleStruct));
	// printf("Address: %lu\n\n",&sa);
	// printf("Address: %lu\n\n",&sb);
	char val1[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("Val2 value before mempcy: %s\n",val1);
	memmove(val1, val1+10, strlen(val1)+1);

	printf("Val2 value after mempcy: %s\n",val1);
	
	return 0;
}