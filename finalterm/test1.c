#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid, child, status,num;

	printf("type num of childs :");
	scanf("%d",&num);


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

int main()
{
	int pid, child, status, num;
	printf("type num of childs :");
	scanf("%d",&num);

	child = wait(&status);
	printf("parent killed - last child id = %d",getpid());
	return 0;
}
