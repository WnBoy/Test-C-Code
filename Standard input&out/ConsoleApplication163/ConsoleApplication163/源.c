#include<stdio.h>
#include"queue.h"

int main(void)
{
	Queue line;
	Item temp;
	char ch;
	InitializeQueue(&line);
	puts("Testing the Queue interface.Type a to add a value,");
	puts("type d to delate a value,and type q to quit.");
	while ((ch = getchar()) != 'q')
	{
		if (ch != 'a'&&ch != 'd')
			continue;
		if (ch == 'a')
		{
			printf("Integer to add:");
			scanf("%d", &temp);
			if (!QueueIsFull(&line))
			{
				printf("Putting %d into queue\n", temp);
				EnQueue(temp, &line);
			}
			else
				puts("Queue is full!");
		}
		else
		{
			if (QueueIsEmpty(&line))
				puts("Nothing to dwleted");
			else
			{
				DeQueue(&temp, &line);
				printf("Removing %d from queue\n", temp);
			}
		}
		printf("%d items in Queue\n", QueueItemCount(&line));
		puts("Type a to add,d to delete,q to quit:");
	}
	EmptyTheQueue(&line);
	puts("Bye!");
	return 0;
}