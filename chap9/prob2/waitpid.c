#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid1, pid2, child, status;

	printf("[%d] Parent Process Start \n", getpid());
	pid1 = fork();
	if (pid1 == 0) {
		printf("[%d] Child Process[1] Start \n", getpid());
		sleep(1);
		printf("[%d] Child Process[1] Stop \n", getpid());
		exit(1);
	}
	pid2 = fork();
	if (pid2 == 0) {
		printf("[%d] Child Process[2] Start \n", getpid());
		sleep(2);
		printf("[%d] Child Process[2] Stop \n", getpid());
		exit(2);
	}
	child = waitpid(pid1, &status, 0);
	printf("[%d] Child Process[1] %d Stop \n", getpid(), child);
	printf("\tStop Code %d\n", status>>8);
}
