#include <stdio.h>
static void exit_handler1(void), exit_handler2(void);

int main(void)
{
	if(atexit(exit_handler1) != 0)
		perror("exit_handler1 Cannot add");
	if(atexit(exit_handler2) != 0)
		perror("exit_handler2 Cannot add");
	printf("main END\n");
	exit(0);
}

static void exit_handler1(void)
{
	printf("Frist exit processer\n"

