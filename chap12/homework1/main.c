#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAXLINE 100

int main()
{
	int n, length, fd[2], pid;
	char message[MAXLINE], line[MAXLINE];

	pipe(fd);

	if((pid = fork()) == 0)
	{
		close(fd[0]);
		printf("Send: [%d] Hello from PID %d\n",getpid(),getpid());
	}else{
		close(fd[1]);
		n = read(fd[1],line,MAXLINE);
		printf("Recv: [%d] Hello from PID %d\n", getpid(),getppid());
	}

	exit(0);
}




