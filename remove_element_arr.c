#include<stdio.h>

char remove_element1(char *ptr, char size, char val)
{
	char i=0,j=0;
	while(i < size)
	{
		if(*(ptr+i) != val)
		{
			printf("%d\n", *(ptr+i));

			i++;
		}
		else
		{
			j = i;
			while(j < size)
			{
				*(ptr + j) = *(ptr + j + 1);
				printf("Replacing: %d with %d\n", *(ptr+j), *(ptr+j+1));
				j++;
			}
			size--;
		}
	}
	return size;
}

char remove_element2(char *ptr, char size, char val)
{
    int i = 0;
    for (int j = 0; j < size; j++) {
        if (*(ptr+j) != val) {
            *(ptr+i)  = *(ptr+j) ;
            i++;
        }
    }
    return i;
}


int main()
{
	char arr[] = {1,2,2,2,2,2,2,4,4,4,4,0,5};
	char size = sizeof(arr)/sizeof(arr[0]);
	char val = 4;
	size = remove_element2(arr, size, val);
	int m=0;
	printf("Printing elements\n");
	while(m<size)
		printf("%d\n",arr[m++] );

	return 0;
}