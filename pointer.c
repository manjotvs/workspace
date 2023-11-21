#include <stdio.h>
#include <stdint.h>


// Test uintptr_t and intptr_t.

void test_int_ptr()
{
	char *name[] = {"Avinnlknjnjnjknkjnash", "Shivani", "TOMO", "RAHUL" };
	int roll_num[4] = { 1234990, 23322, 9494, 1010 };

	uintptr_t *cptr= (uintptr_t *)&name[0];
	//uintptr_t **cptr = (uintptr_t *)&name;
	uintptr_t *iptr = (uintptr_t *)&roll_num;
	printf("addr1: %p\n", &name[1]);
	printf("addr2: %p\n", &name[2]);
	printf("addr3: %p\n", &name[3]);

	printf("%s %d\n", (char*)cptr[0], (int)(iptr[0]));
	printf("%s %d\n", (char*)*(cptr+1), *((int*)iptr+1));
	printf("%s %d\n", (char*)*(cptr+2), *((int*)iptr+2));
	printf("%s %d\n", (char*)*(cptr+3), *((int*)iptr+3));

}

typedef struct words{ 
	int16_t v[2];
}words;

void pointer_aliasing(int32_t *pv, words *pw)
{
	for (int i = 0; i < 5; i++)
	{
		(*pv)++;
		// Print the 32-bit value and the 16-bit values:
		printf("%x, %x-%x\n", *pv, pw->v[1], pw->v[0]);
	}
}

void pointer_sizes()
{
	printf("char* size: %lu\n", sizeof(char *));
	printf("int* size: %lu\n", sizeof(int *));
	printf("uintptr_t size: %lu\n", sizeof(uintptr_t));

}

void play_pointer()
{
	char myChar, *pChar;
	float myFloat, *pFloat;

	pChar = &myChar;
	pFloat = &myFloat;

	printf( "pChar:  %p\n", ( void* )pChar );
	printf( "pFloat: %p\n", ( void* )pFloat );

	pChar++;
	pFloat++;

    // Issues with below casting, better way to handle it given above.
	printf( "and then after incrementing,:\n\n" );
	printf( "pChar:  %d\n", (int)pChar );
	printf( "pFloat:    %d\n", (int)pFloat );
}


int main()
{
	// Check  pointer size
	pointer_sizes();
	test_int_ptr();
	{
		int32_t v = 0x12345678;
		words *pw = (words *)&v; // Violates strict aliasing
		pointer_aliasing(&v, pw);
	}

	{
		play_pointer();
	}

	return 0;
}
