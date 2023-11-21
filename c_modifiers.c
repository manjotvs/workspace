#include<stdio.h>

int main()
{
     
     printf("int: %lu\n",sizeof(int));
     printf("long int: %lu\n",sizeof(long int));
     printf("long: %lu\n",sizeof(long));
     printf("long long int: %lu\n",sizeof(long long int));
     printf("long long %lu\n",sizeof(long long));
     printf("char: %lu\n",sizeof(char));
     printf("double: %lu\n",sizeof(double));
     printf("long double: %lu\n",sizeof(long double));
     printf("float: %lu\n",sizeof(float));
     printf("size_t: %lu\n",sizeof(size_t));
     return 0;
}