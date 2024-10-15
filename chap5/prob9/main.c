#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

	int fd;
	int line = 0, pos = 0;
	char buf;
	char savedText[100][100];
	char input[100];
	if(argc < 2){
		fprintf(stderr, "How to use %s file\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}

	while(read(fd,&buf,1) > 0){
		if(buf == '\n'){
			savedText[line][pos] = '\0';
			line++;
			pos = 0;
		}else{
			savedText[line][pos] = buf;
			pos++;
		}
	}

	line--;
	for(;line>-1;line--)
		printf("%s\n",savedText[line]);
	close(fd);
	exit(0);
}









/*	int fd, id;
	char c;
	struct student record;
	if(argc < 2){
		fprintf(stderr, "How to use %s file\n", argv[0]);
		exit(1);
	}

	if ((fd = open(argv[1], O_RDWR)) == -1) {
		perror(argv[1]);
		exit(2);
	}

	do{
		printf("Enter StudentID to be modified: ");
		if (scanf("%d", &id) == 1) {
			lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
			if((read(fd, (char *) &record, sizeof(record)) >0) && (record.id != 0)) {
				printf("StuID:%8d\t Name:%4s\t Score:%4d\n",
						record.id,record.name,record.score);
				printf("Enter New Score: ");
				scanf("%d", &record.score);
				lseek(fd, (long) -sizeof(record), SEEK_CUR);
				write(fd, (char *) &record, sizeof(record));
			} else printf("Record %d Null\n", id);
		} else printf("Insert Error\n");
		printf("Continue?(Y / N)");
		scanf(" %c",&c);
	}while (c == 'Y');
	close(fd);
	exit(0);
} */
