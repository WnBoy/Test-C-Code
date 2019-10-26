#include<stdio.h>
int main()
{
	int s[10][10];
	int i, j;
	for (i = 0;i < 10;i++)
	{
		s[i][i] = 1;
		s[i][0] = 1;
	}
	for (i = 2;i < 10;i++)
		for (j = 1;j < i-1;j++)
			s[i][j] = s[i - 1][j] + s[i - 1][j - 1];
	for (i = 0;i < 10;i++)
	{
		for (j = 0;j <= i;j++)
			printf("%6d", s[i][j]);
		printf("\n");
	}
	printf("\n");
	getchar();
	return 0;
}