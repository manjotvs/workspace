#include <stdio.h>

void main()
{
	int i = 11;
    i = i++ + i++ + i++;
    printf("%d\n",i);
}