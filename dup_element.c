#include<stdio.h>

char dup1(char *ptr, char size)
{
	char i=0,j=0,k=0,dup=0;
	printf("size:%d\n",size);
	while(i < size)
	{
		printf("Looping: %d\n",i);
		j = i + 1;
		while((*(ptr+i) == *(ptr+j)) && j < size)
		{
			printf("Dup element at %d\n",j);
			dup++;
			j++;
		}
		if(dup)
		{
			j=dup;
			k=i;
			while(k < size)
			{
				printf("Replacing %d with %d\n",k,k+dup);
				*(ptr+k) = *(ptr+k+j);
				//dup--;
				k++;
			}
			size = size - dup;
			dup = 0;
		}
		i++;
	}
	return size;
}

char dup2(char *ptr, char size)
{
	char i=0,j;
	printf("size:%d\n",size);

	for(j = 1; j < size; j++)
	{
		if(*(ptr+i)!= *(ptr+j))
		{
			i++;
			
		}
		*(ptr+i) = *(ptr+j);
		//size--;
	}
	return i+1;
}
int main()
{
	char arr[] = {0,1,2,3,4,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,7,7,7,8,8,8,9,9,};
	char s = sizeof(arr)/sizeof(arr[0]);
	//printf("size:%d\n",s);
	
	s = dup2(arr,s);
	int m=0;
	printf("Printing elements\n");
	while(m<s)
		printf("%d\n",arr[m++] );
}