#include<stdio.h>
#include<stdint.h>

#define C_TO_F(degC) ({\
	degC * ((typeof(degC))22/7) + 32;\
})

#define C_TO_F2(degC) ({\
	degC * (22/(typeof(degC))7) + 32;\
})
int main()
{
	{
		float n1 = 2.3;
		int n2 =2;

		printf("Temp: %f\n", C_TO_F(n1));
		printf("Temp: %d\n", C_TO_F(n2));
	}

	{
		int n=0x12345678;
		void* p = &n;
		printf("0x%2X\n", *((uint8_t*)p));
		printf("0x%2X\n", *((uint16_t*)p));
		printf("0x%2X\n", *((uint32_t*)p));


	}
	return 0;
}