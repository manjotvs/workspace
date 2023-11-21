#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
// frist example
//int count = 0;
// second example 
volatile sig_atomic_t count = 0;
void sigint_handler(int signum) {
    // The compiler is allowed to run:
    //
    //   signal(signum, SIG_DFL)
    //
    // when the handler is called. So we reset the handler here:
    signal(SIGINT, sigint_handler);
    (void)signum; // Get rid of unused variable warning
    //first example
    // count++; // Undefined behavior printf("Count: %d\n", count); // Undefined behavior
    // if (count == 3) 
    // { 
    //     printf("Exiting!\n"); exit(0);
    // } 


    // second example
    count++;

}
int main(void)
{

    signal(SIGINT, sigint_handler);
    printf("Try hitting ^C...\n");
    // first example
    // {
    //     for(;;); // Wait here forever 
    // }
    //second example
    while(count<2)
    {
        printf("%d",count);
        fflush(stdout);
        sleep(1);
    }

    //return 0;
}
