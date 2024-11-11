#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc,char * argv[])
{
	if (argc < 2)
	{
		fprintf(stderr,"Error : %s\n",argv[0]);
		return 1;
	}


	if(strcmp(argv[1], "-e") == 0)
	{
		char *finePath = argv[2];
		char *ptr;
		ptr = getenv(finePath);
		printf("Path = %s\n",ptr);
	}

	if(strcmp(argv[1], "-u") == 0)
	{
		printf("My Realistic User ID : %d(%s) \n", getuid(), getpwuid(getuid())->pw_name);
		printf("My Vaild User ID : %d(%s) \n", geteuid(), getpwuid(geteuid())->pw_name);
	}

	if(strcmp(argv[1], "-g") == 0)
	{
		printf("My Realistic Group ID : %d(%s) \n", getgid(), getgrgid(getgid())->gr_name);
		printf("My Valid Group ID : %d(%s) \n", getegid(), getgrgid(getegid())->gr_name);
	}

	if(strcmp(argv[1], "-i") == 0)
	{
		printf("My Process Number : [%d] \n",getpid());
	}

	if(strcmp(argv[1], "-p") == 0)
	{
		printf("My Parent Process number : [%d] \n",getppid());
	}


	return 0;
}

