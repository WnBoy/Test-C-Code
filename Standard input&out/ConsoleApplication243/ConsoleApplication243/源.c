#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct file {
	char title[20];
	int rating;
	struct file*next;
};

int main(void)
{
	FILE*fp;
	struct file*head;
	struct file*pre, *current=NULL;
	char input[20];
	puts("Please input file name:");
	while (gets(input) != NULL&&input[0] != '\0')
	{
		current = (struct file*)malloc(sizeof(struct file));
		if (current == NULL)
		{
			puts("Memory allocation failed.Goodbye.");
			exit(EXIT_FAILURE);
		}
		if (head == NULL)head = current;
		else pre->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Please input rate:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		pre = current;
		puts("Please input next file name:");
	}
	current = head;
	if (current == NULL)puts("This is chain empty");
	else
		while (current != NULL)
		{
			printf("this move title is:%s,rating is:%d", current->title, current->rating);
			current = current->next;
		}
	current = head;
	while (current != NULL)
	{
		free(current);
		current = current->next;
	}
	puts("Bye!");
	getchar();
	return 0;
}