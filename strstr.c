#include <stdio.h>

char strStr(char *str1, char *str2)
{
	char i = 0,j=0;
	char str_pos =-1;
	while(str1[i] != '\0')
	{
		j=0;
		str_pos = i;
		while(str2[j] == str1[i])
		{
			
			j++;
			i++;
		}
		i++;
	}
	return (str2[j] == '\0') ? (str_pos): (-1);
}

int main()
{
	char str1[]= "Haystackl";
	char str2[]= "stack";
	char pos=strStr(str1, str2);
	if(pos > 0)
		printf("Pos: %d\n", pos );
	else
		printf("Not found\n");

	return 0;
}