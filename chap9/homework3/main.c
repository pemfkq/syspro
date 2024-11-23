#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void excute_cmd(char *cmd);

int main() {
	char input[100];

	printf("[shell]");
	scanf("%s", input);
	char *cmd = strtok(input, ";");
	while (cmd != NULL) {
		execute_cmd(cmd);
		cmd = strtok(NULL,";");
	}
}

void execute_cmd(char *cmd)
{
	int pid;
	int background = 0;
	char *token = strtok(cmd, " ");

	while(token != NULL)
	{
		if (strcmp(token, "&") == 0)
			background = 1;
		else if (strcmp(token,"<") == 0)
		{

	
