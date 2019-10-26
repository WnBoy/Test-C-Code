#include<stdio.h>
int main(void)
{
	char c;
	int n=0;
	while ((c = getchar()) != '#')
	{
		n++;
		printf(" %c %d ", c, c);
		if (n % 8 == 0)putchar('\n');
	}
	getchar();
	getchar();
	return 0;
}