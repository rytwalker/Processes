// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int child = fork();

    if (child < 0)
    {
        fprintf(stderr, "fork failed.");
        exit(1);
    }
    else if (child == 0)
    {
        printf("hello\n");
    }
    else
    {
        waitpid(child, NULL, 0);
        // wait(NULL);
        printf("goodbye\n");
    }

    return 0;
}
