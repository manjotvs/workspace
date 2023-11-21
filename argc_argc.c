#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	printf("hijifkjn\n");
	for(int i=0;i<argc;i++)
	{
		printf("%s \n",argv[i]);
	}

		sleep(10);
	strcpy(argv[0], "titan");
	while(1)
	{
		sleep(1000);
	}
	return 0;
}