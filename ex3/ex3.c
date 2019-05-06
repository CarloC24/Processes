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
    int counter = fork();
    if (counter == 0)
    {
        printf("This is the child process \n");
        exit(1);
    }
    else
    {
        wait(NULL);
        printf("This is the parent process \n");
    }

    return 0;
}
