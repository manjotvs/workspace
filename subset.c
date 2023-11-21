#include <stdio.h>
#include <math.h>

#define SET_BIT(val, pos) (val |= ((0x1) << pos))
#define CLEAR_BIT(val, pos) (val &= ~((0x1) << pos))
#define BIT_SET(val,pos) (val & (0x1 << pos))
// int sizeInBits = sizeof(mask) * BITS_PER_BYTE; // BITS_PER_BYTE = 8;
// mask = (param >= sizeInBits ? -1 : (1 <<  param) - 1);
// Width is the total number of bits in a whole word and i varies from (0 to n-1) then use following

#define BIT_MASK(i, s) ((i > s) ? -1: (1 << i) - 1 )

void bit_set(char *val, char pos)
{
	*val |= (0x1 << pos);
}

void bit_unset(char *val, char pos)
{
	*val &=(~(1 << pos));
}

char find_subsets_val(char *a, char size, char val)
{
	char sum = 0, j=0;
	char no_of_subsets = 0;
	//printf("\n\nTotal number of elements are %d.\n", size );
	for(char i=0; i <= (pow(2,size) -1 ); i++)
	{
		sum =0;
		for(j=0;j<size;j++)
		{
			if(BIT_SET(i,j))
				sum = sum + a[j];
			if(sum >= val)
				no_of_subsets++;
			//printf(" For i = %d sum is %d\n",i,sum );
		}
	}
	return no_of_subsets;
}

char find_subsets(char *a, char size)
{
	char j=0;
	char set[3];
	char no_of_subsets = 0;
	printf("\n\nTotal number of elements are %d.\n", size );
	for(char i=0; i <= (pow(2,size) -1 ); i++)
	{

		printf(" For i = %d (",i);
		for(j=0;j<size;j++)
		{
			if(BIT_SET(i,j))
			{
				no_of_subsets++;
				printf(" %d ", a[j]);
			}
		}
		printf(")\n");
	}
	return no_of_subsets;
}
int main()
{
	char a= 0xF0;

	SET_BIT(a, 0); 
	printf("Val after bitmasking: 0x%02X\n",a & 0xFF);
	CLEAR_BIT(a, 7);
	printf("Val after bitmasking: 0x%02X\n",a & 0xFF);
	
	SET_BIT(a, 1);
	printf("Val after bitmasking: 0x%02X\n",a & 0xFF);
	CLEAR_BIT(a, 6);
	printf("Val after bitmasking: 0x%02X\n",a & 0xFF);
	
	SET_BIT(a, 2);
	printf("Val after bitmasking: 0x%02X\n",a & 0xFF);
	CLEAR_BIT(a, 5);
	printf("Val after bitmasking: 0x%02X\n",a & 0xFF);
	
	SET_BIT(a, 3);
	printf("Val after bitmasking: 0x%02X\n",a & 0xFF);
	CLEAR_BIT(a, 4);
	printf("Val after bitmasking: 0x%02X\n",a & 0xFF);
	char pos = 0;
	printf("%dth bit is %1X in val!!!\n", pos, BIT_SET(a,pos));

	char b[] = {1,2,3};
	char val = 1;
	printf("Number of subsets whose sum of elements is greater than or equal to %d are %d!!!\n\n", val, find_subsets_val(b, (sizeof(b)/sizeof(b[0])), val));
	find_subsets(b,(sizeof(b)/sizeof(b[0])));

	char i = 3;
	printf("Bitmask for the i: %d position: 0x%0002X\n", i, BIT_MASK(i, 31));
	return 0;
}