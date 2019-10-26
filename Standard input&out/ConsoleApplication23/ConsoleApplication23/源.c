#include<stdio.h>
int main()
{
	char s[6] = { "*****" };
	int i, j;
	for (i = 1;i <= 5;i++)
	{
		printf("\n");
		for (j = 1;j < i;j++)
			printf(" ");
		printf("%s", s);
	}
	printf("\n");
	getchar();
	return 0;
}