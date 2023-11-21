#include<stdio.h>


#define TYPESTR(x) _Generic((x), \
			int: "int", \
			float: "float", \
			double: "double", \
			char: "char", \
			default: "something else")

int sum(int a, int b)
{
	return a+b;
}

int sum_arr(int a[], int size)
{
	int i = 0;
	int sum = 0;
	while(i<size)
	{
		sum+=*(a+i);
		i++;
	}
	return sum;
}

int main()
{
	int a = 2;
	int b =3;
	float c;
	double d;
	char e;
	int *f;
	printf("%s\n", TYPESTR(a));
	printf("%s\n", TYPESTR(b));
	printf("%s\n", TYPESTR(c));
	printf("%s\n", TYPESTR(d));
	printf("%s\n", TYPESTR(e));

	printf("%s\n", TYPESTR(f));
	printf("%d\n",sum(a,b));
	printf("%d\n",sum((int){2},(int){3}));

	int arr[5] = {1,2,3,4,5};
	printf("%d\n",sum_arr(arr,5));
	printf("%d\n",sum_arr((int[]){1,2,3,4,5},(int){5}));

	printf("%d\n",sum_arr((int[5]){1,2,3,4,5},(int){5}));
	return 0;

}