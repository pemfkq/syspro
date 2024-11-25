#include <stdio.h>
#include <unistd.h>
#include <signal.h>
struct sigaction newact;
struct sigaction oldact;
void alarm_handler(int signo);


int main()
{
	newact.sa_handler = alarm_handler;
	sigfillset(&newact.sa_mask);

	sigaction(SIGALRM,&newact, &oldact);

	alarm(5);
	short i = 0;
	while(1) {
		sleep(1);
		i ++;
		printf("%d second\n",i);
	}
	printf("end\n");
}

void alarm_handler(int signo)
{
	printf("Wake up\n");
	exit(0);
}


