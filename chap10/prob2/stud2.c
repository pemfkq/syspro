#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	int id;
	char name[20];
	struct student *next;
};

int main()
{
	int count = 0, id;
	char name[20];
	struct student *p, *head = NULL;

	printf("Type Student number and name\n");
	while(scanf("%d %s", &id, name) == 2) {
		p = (struct student *) malloc(sizeof(struct student));
		if (p == NULL) {
			perror("malloc");
			exit(1);
		}
		p->id = id;
		strcpy(p->name, name);
		p->next = head;
		head = p;
	}

	printf("\n* Student INFO *\n");
	p = head;
	while (p != NULL) {
		count++;
		printf("Student Number : %d  Name: %s \n", p->id, p->name);
		p = p->next;
	}
	printf("Total %d student \n",count);
	exit(0);
}
