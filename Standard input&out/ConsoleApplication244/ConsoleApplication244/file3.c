#include<stdio.h>
#include<stdlib.h>
#include"list.h"
void showmvies(Item item);
int main(void)
{
	List moves;
	Item temp;
	InitializeList(&moves);
	if (ListIsFull(&moves))
	{
		fprintf(stderr, "NO memory!");
		exit(1);
	}
	puts("Enter the first move name:");
	while (gets(temp.title) != NULL&&temp.title[0] != '\0')
	{
		puts("Please enter rating:");
		scanf("%d", &temp.rating);
		while (getchar() != '\n')
			continue;
		if (AddItem(temp, &moves) == false)
		{
			fprintf(stderr, "problem allocating memory\n");
			break;
		}
		if (ListIsFull(&moves))
		{
			puts("The list is full.");
			break;
		}
		puts("Please enter next move name:");
	}
	if (ListIsEmpty(&moves))
		printf("No date enter!");
	else
	{
		printf("Here is the move list:");
		Traverse(&moves, showmvies);
	}
	fprintf(stdout, "you entered %d movies.\n", ListItemCount(&moves));
	EmptyTheList(&moves);
	puts("Bye!");
	getchar();
	return 0;
}

void showmvies(Item item)
{
	printf("Movie:%s rating:%d\n", item.title, item.rating);
}