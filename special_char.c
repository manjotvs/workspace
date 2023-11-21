#include <stdio.h>
#include <unistd.h>

int main()
{
	for(int i =10;i>0;i--)
	{
		printf("\rT minus %d second%s... \b\b\b\b\b\b\b\b\b\b\b\b\b", i, (i!=1)?"s":"");
		fflush(stdout); // This is important because there will no ouput to stdout until there is a new line feed
		sleep(1);

		// '/b' moving cursor but doesn't delete the character
		// '/r' bringing the cursor to first position on the line.
	}
	return 0;
}
