#include <stdio.h>
#include <string.h>


void reverseString(char* s, int sSize){
	int i = 0;
	int j = sSize -1;
    while(i < sSize/2)
    {
    	s[i] = s[i] ^ s[j];
    	s[j] = s[i] ^ s[j];
    	s[i] = s[i] ^ s[j];
    	i++;
    	j--;
    }
}

int main()
{
	char arr[] = "Hello";
	reverseString(arr, strlen(arr));
	printf("Reverse Strings %s\n", arr );
	return 0;
}