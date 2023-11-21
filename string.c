#include <stdio.h>

void main()
{
	char *str1 = "Hello";
	//str1[0] = 'M';
	char str2[] = "SSA MANJOT SINGH";
	str2[0] = 'L';
	printf("%s    %s\n",str1,str2);
	printf("Adddress of *str are %p %p\n",str1, &str1);
	printf("Adddress of str2[] are %p %p %p\n",str2, &str2, &str2[0]);

}

