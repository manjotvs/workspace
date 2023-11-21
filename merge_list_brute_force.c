#include <stdio.h>
#include <stdlib.h>
void merge(int *nums1, int m, int *nums2, int n) 
{
	char i=m;
	char temp;
	while((m+n)>=0)
	{
		//printf("M+N: %d\n", m+n);
		if(*(nums1+(m-1)) >= *(nums2+(n-1)))
		{
			*(nums1+(m+n-1)) = *(nums1+(m-1));
			//printf("M: %d\n", m);

			//printf("Value: %d\n", *(nums1+(m+n-1)));
			m--;
		}
		else
		{
			*(nums1+(m+n-1)) = *(nums2+(n-1));

			//printf("Value: %d\n", *(nums1+(m+n-1)));
			//printf("N: %d\n", n);
			n--;
		}
	}
}

int main()
{
	int a[10] = {1,2,3,5,9};
	int b[] ={3,4,6,7,8};

    char i=0;
	merge(a, 5, b,  (sizeof(b)/sizeof(b[0])));
	while(i<10)
		printf("%d\n",a[i++]);
	return 0;

}