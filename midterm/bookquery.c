#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "booklist.h"

int main(int argc, char *argv[])
{
	int fd, loadType, id=1,check;
	char c;
	struct bookList list;
	fd = open(argv[1], O_RDONLY);

	printf("--bookquery--\n");
	printf("0: list of all books, 1: list of available books )");
	scanf("%d", &loadType);

	printf("%-3s %-9s %-9s %-3s %-15s %-3s\t\n", "id", "bookname", "author",
			"year", "numofborrow", "borrow");
	while(1){
		lseek(fd, (id-1)*sizeof(list), SEEK_SET);
		if ((read(fd, (char *) &list, sizeof(list)) > 0)){
			check = list.borrow;
			if(check == 0 && loadType == 1){
				id++;
				continue;
			}
			printf("%-3d %-9s %-9s %-3d %-15d", list.bookID, list.bookName,
					list.author, list.year, list.numOfBorrow);

			if(check == 0)
				printf("FALSE\n");
			else
				printf("TRUE\n");
		}else
			break;
		id++;
	}
		

	close(fd);
	exit(0);
}

	
