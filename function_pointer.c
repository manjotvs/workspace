#include<stdio.h>


typedef int (*func_ptr_t)(int, int);
func_ptr_t funcp[3];
int (*func[3])(int, int);

int (*func1)(int, int);

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int mul(int a, int b)
{
	return a*b;
}
// Fucntion pointer
int main()
{
	funcp[0] = add;
	funcp[1] = sub;
	funcp[2] = mul;

	int a = 123;
	int b = 546;

	for(int i=0;i<3;i++)
	{
		printf("%d\n",funcp[i](a,b));
	}

	func[0] = &add;
	func[1] = &sub;
	func[2] = &mul;
	for(int i=0;i<3;i++)
	{
		printf("%d\n",func[i](a,b));
	}
	func1 = &add;
	//int x = (*func1)(2,3);
	int x = func1(2,3);
	printf("%d\n",x);
	return 0;
}