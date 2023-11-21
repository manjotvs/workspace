#include <stdio.h>
#include <stdlib.h>

const int x = 12;
	 const int y = x+1;

void main()
{
	 int a = 12;
	 switch(a)
	 {
	 case y:
	 	printf("hello\n");
	 	break;
	 case x:
	 	printf("SSA\n");
	 	break;
	 default:
	 	printf("HI\n");
	 }
	printf("%d\n",y);
	int *p =&y;
	*p=200000001;
	printf("%d %d\n",y,*p);
	printf("%p, %p\n",&y,p);

}