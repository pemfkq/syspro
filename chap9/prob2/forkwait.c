#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid, child, status;
	printf("[%d] Parent Process Start \n", getpid());
	pid = fork();
	if (pid == 0) {
		printf("[%d] Child Process Start \n", getpid());
		exit(1);
	}
	child = wait(&status);
	printf("[%d] Child Process %d Stop \n", getpid(), child);
	printf("\tStop Code %d\n", status>>8);
}
