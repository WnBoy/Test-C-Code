#include<stdio.h>
#define PERIOD '.'
int main(void)
{
	int ch;
	int charcount = 0;
	printf("\a");
	while ((ch = getchar()) != PERIOD)
	{
		if (ch != '"'&&ch != '\'')
			charcount++;
	}
	printf("There are %d non-quote characters.\n", charcount);
	getchar();
	getchar();
	return 0;
}