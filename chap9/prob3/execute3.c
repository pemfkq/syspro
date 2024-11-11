#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int child, pid, status;
	printf("Parent Process Start\n");
	pid = fork();
	if (pid == 0) {
		execvp(argv[1], &argv[1]);
		fprintf(stderr, "%s:Can not start\n",argv[1]);
	}else{
		child = wait(&status);
		printf("[%d] Child Process %d Stop \n", getpid(), pid);
		printf("\tStop Code %d \n", status>>8);
	}
}

