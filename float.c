#include <stdio.h>
#include <float.h>
int main()
{
	//34567000
	float c  = 3.4567e7;
	printf("%d\n",c); 
	float a = 0.123456F;
	float  b = 123448390.1;
	printf("%.11f %f\n",a,b);

	printf("%d\n", FLT_RADIX);
	printf("%d\n", FLT_DECIMAL_DIG);

	printf("%f, %e, %g\n",c,c,c);

	printf("%.14f\n", FLT_MIN);
	printf("%f\n", FLT_MAX);
	return 0;
}