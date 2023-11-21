#include<stdio.h>

char str[][10] = {"uelloijkl","hellohello", "iellohello","lellohello"};
int find_prefix(char n, char l)
{

	char c = str[0][0];
	char f = 0;
	int i=0,j=0;
	for(j=0;j<l;)
	{
		for(i=0;i<n;)
		{
			if((str[i][j]) == c)
			{
				i++;
				//printf("Found match: %c %d\n", c,i);
			}
			else
				return f;
		}
		if(i == n)
		{
			f++;
		}
		c = str[0][++j];
	}
	return f;
}
int main()
{	
	// n is nos of strings and l is maximum length
	char n=find_prefix(4,9);
	printf("Longest prefix:");
	if(n)
	{
		for(int i=0;i<n;i++)
			printf("%c",str[0][i]);
	}
	printf("\n");
	return 0;
}