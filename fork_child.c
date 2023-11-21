//  child.c: the child program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

    
int main (int argc, char **argv)
{   
    int j;

    printf ("Child(%d): Hello, World!\n", getpid());
    printf("Arguments: ");
    char *myargs [] = { NULL };
    execvp ("./child", myargs);
    for(j=0; j < argc; j++)
    {
        printf("%s ", argv[j]);
    }
    printf("\n");

    for (j = 0; j < 2; j++ ) {
        sleep(1);
    
    }

    printf ("Child: Work completed!\n");
    printf ("Child: Bye now.\n");

    exit (0);
}