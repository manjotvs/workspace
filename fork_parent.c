#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int pr()
{
    char *myargs [] = { NULL };
    exit(0);
    //execv("./child", myargs);
    return 0;
}


// int main(int argc, char *argv[])
// {
//     int numChildren=10, j;
//     pid_t childPid;
//     // setbuf(stdout, NULL);
//     // for (j = 0; j < numChildren; j++)
//     // { 
//     //     switch (childPid = fork())
//     //     { 
//     //         case -1:
//     //             printf("failed");
//     //         case 0:
//     //             printf("%d child\n", j); _exit(EXIT_SUCCESS);
//     //         default:
//     //             printf("%d parent\n", j); wait(NULL);
//     //         break;
//     //     } 
//     // }
//     // exit(EXIT_SUCCESS);
//     fork();
//     fork();
//     fork();
//     printf("hello\n");
// }
int main (int argc, char **argv)
{
    int i = 0;
    long sum=0;
    int pid;
    int status, ret;
    char *myargs [] = { NULL };
    char *myenv [] = { NULL };
    int pipefd[2];
    char buf;
    char msg[] = "hello, how you are doing";
    // Create a Pipe
    pipe(pipefd);

    //http://man7.org/linux/man-pages/man2/pipe.2.html
    pid = fork();
    if (pid == 0) {
        printf("Child(%d): Created!\n", getpid());
        close(pipefd[1]);
        write(pipefd[0], msg, strlen(msg));
        write(pipefd[0], msg, strlen(msg));
        //
        printf("Waiting for parent to respond\n");

        // while (read(pipefd[0], &buf, 1) > 0)
        // {
        //    // printf("char: %c\n",buf);
        //     write(STDOUT_FILENO, &buf, 1);
        // }
        //write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);
        // I am the child
        //execv("./child", myargs);
        /* Following routines are only required when exec call hasn't been made */
        //sleep(15);
        //exit(0);
    }
    else
    {
        printf("Waiting for child to initiate the communication\n");
        //         /* Close unused read end */
        close(pipefd[0]); 
        while (read(pipefd[1], &buf, 1) > 0)
        {
           // printf("char: %c\n",buf);
            write(STDOUT_FILENO, &buf, 1);
        }
        write(STDOUT_FILENO, "\n", 1);

        //write(pipefd[1], msg, strlen(msg));
        close(pipefd[1]); 
        printf("Parent: Waiting for Child to complete.\n");

        if ((ret = waitpid(pid, &status, 0)) == -1)
            printf("parent:error\n");

        printf("Parent: Child process waited for.\n");
    }
}