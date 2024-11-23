#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void addq(struct node **head, struct node **tail, int data);
int delete(struct node **head, struct node **tail);

struct node *head = NULL;
struct node *tail = NULL;

int main()
{
	int num;
	float rnum;
	int value;

	while(1)
	{
		scanf("%f",&rnum);
		num = rnum;
		addq(&head, &tail, num);
		if(num != rnum)
			break;
	}

	printf("print queue\n");

	while(1)
	{
		if(head == NULL)
			break;
		value = delete(&head, &tail);
		printf("%d\n",value);
	}

	return 0;
}

void addq(struct node **head, struct node **tail, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	if (*tail != NULL)
		(*tail)->next = temp;

	*tail = temp;

	if (*head == NULL)
		(*head) = temp;
}

int delete(struct node **head, struct node **tail)
{
	struct node *temp = *head;
	int data = temp->data;
	*head = (*head)->next;

	free(temp);
	return data;
}
