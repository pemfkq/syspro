#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Parent Process Start\n");
	if (fork() == 0) {
		execl("/bin/echo", "echo", "hello" , NULL);
		fprintf(stderr, "Frist Failure");
		exit(1);
	}
	printf("parent Process Stop\n");
}
