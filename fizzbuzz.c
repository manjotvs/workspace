#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ** fizzBuzz(int n, int* returnSize){
    char **arr = (char**)malloc(sizeof(char*)*n);
    for(int i = 0; i < n;i++)
    {
        char *str = malloc(sizeof(char)*9);
        arr[i] = str;
        
        sprintf(str, "%d", i+1);
        if((i+1)%3==0)
        {
            strcpy(str, "Fizz");
        }
        if((i+1)%5==0)
        {
            strcpy(str,"Buzz");
        }
        if((i+1)%15==0)
        {
            strcpy(str,"FizzBuzz");
        }
    }
    *returnSize = n;
    return arr;

}
int main()
{
// 	static int i = 0;
//   fork();fork();fork();fork(); printf("hello world: %d\n",i++);
	int size = 0;
	int n =15;
	char **ans;
	ans = fizzBuzz(n, &size);
	int i = 0;
	while(i<n)
		printf("%s\n", ans[i++]);
}