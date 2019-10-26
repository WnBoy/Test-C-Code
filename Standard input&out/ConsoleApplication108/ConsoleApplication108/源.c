#include<stdio.h>
int main(void)
{
	char ch;
	int n=0;
	printf("please enter cahr:\n");
	while ((ch = getchar()) != '#')
	{
		++n;
		printf("%c %d", ch, ch);
		if (n % 8 == 0)putchar('\n');
	}
	getchar();

	return 0;
}