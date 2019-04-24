// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp;
    int c;
    int n;

    fp = fopen("text.txt", "r");
    c = fork();
    n = fgetc(fp);
    if (c == 0)
    {
        // Child process cant access the file that we have;
        printf("this is the child process with %c char \n", n);
    }
    else
    {
        //Parent process can do the opposite of what the child process can do.
        printf("this is the parent process with %c char \n", n);
    }
    fclose(fp);

    return 0;
}
