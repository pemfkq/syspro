#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **top, int data);
int pop(struct node **top);

struct node *top = NULL;

int main()
{
	int num;
	float rnum;
	int value;

	while(1)
	{
		scanf("%f",&rnum);
		num = rnum;
		push(&top, num);
		if(num != rnum)
			break;
	}

	printf("print stack\n");

	while(1)
	{
		if(top == NULL)
			break;
		value = pop(&top);
		printf("%d\n",value);
	}

	return 0;
}

void push(struct node **top, int data)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->data = data;
	p->next = *top;
	*top = p;
}

int pop(struct node **top)
{
	struct node *temp = *top;
	int data = temp->data;
	*top = (*top)->next;
	free(temp);
	return data;
}
