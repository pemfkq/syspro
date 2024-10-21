#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "booklist.h"

int main(int argc, char *argv[])
{
	int fd;
	struct bookList list;
	fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0640);

	printf("%-3s %-9s %-9s %-3s %-3s %-3s\n", "ID", "bookname", "author",
			"year","numOfBorrow","borrow");
	while (scanf("%d %s %s %d %d %d", &list.bookID, list.bookName, list.author,
				&list.year, &list.numOfBorrow, &list.borrow) == 6) {
		lseek(fd, (list.bookID-1) * sizeof(list), SEEK_SET);
		write(fd, (char *)&list , sizeof(list));
	}
	close(fd);
	exit(0);
}

