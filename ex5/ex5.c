// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    char buf[128];
    int fd[2];
    if (pipe(fd) == -1)
    {
        fprintf(stderr, "piping failed");
        exit(1);
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "forking failed");
    }
    else if (pid == 0)
    {
        write(fd[1], msg1, MSGSIZE);
        write(fd[1], msg2, MSGSIZE);
        write(fd[1], msg3, MSGSIZE);
    }
    else
    {
        read(fd[0], buf, MSGSIZE);
        printf("%s \n", buf);
        read(fd[0], buf, MSGSIZE);
        printf("%s \n", buf);
        read(fd[0], buf, MSGSIZE);
        printf("%s \n", buf);
    }
    return 0;
}
