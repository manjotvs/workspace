#include <stdio.h>
char str[][20] = { "abcdefghijkl","abcdefghijkl","abcdefghijkl" };

// n - number of strings
// l = len of smallest string
// prefix_len = length of possible prefix
// 		-1 -> no prefix found
// 		 n -> lenght of prefix
char find_prefix(char n, char len)
{
	char i =1,j=0;
	char prefix = str[0][0];
	char prefix_len=-1;
	while(j < len)
	{
		i = 1;
		while(i < n)
		{
			if(prefix != str[i][j])
				return prefix_len;
			else
				i++;

		}
		prefix_len++;
		prefix = str[0][++j];
	}
	return prefix_len;
}

int main()
{
	char l = find_prefix(3, 20);
	char i=0;
	if(l > 0)
	{
		printf("Prefix found!: ");
		while(i <= l)
		{
			printf("%c", str[0][i]);
			i++;
		}
		printf("\n");
	}
	else
		printf("No prefix found!\n");
}