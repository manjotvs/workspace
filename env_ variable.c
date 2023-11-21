#include <stdio.h>
#include <stdlib.h>
int main()
{
	char* name = getenv("SUNNY");
	printf("Hostname: %s\n", name);
	return 0;
}