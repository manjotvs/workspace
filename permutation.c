//triplets
#include <stdio.h>

int main()
{
	int triplets=0;
	int arr[] = {7,2,5,4,3,6,1};
	int arr1[] = {1,2,3,4,5,6,7};
	int n =7;
	// for(int i=0; i<=n-3;i++)
	// {

	//     int count=0;
	// 	for(int j=i;j<n;j++)
	//     {
	// 		if(arr1[j]==arr[j])
	// 		{
	// 			count++;
	// 			if(count==3)
	// 			{
	// 				triplets++;
	// 				//i+=3;
	// 				break;
	// 			}
	// 		}
	// 	}
	// }
	for(int i=0; i<=n-3;i++)
	{

	    int count=0;
		for(int j=i;j<n;j++)
	    {
			if(arr[j]==arr1[j])
			{
				count++;
				if(count==3)
				{
					triplets++;
					//i+=2;
					break;
				}
			}
		}
	}
	printf("triplets: %d\n",triplets);
	return 0;
}