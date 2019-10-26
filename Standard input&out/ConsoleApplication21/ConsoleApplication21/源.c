#include<stdio.h>
#define N 10
int main()
{
	int i, j, s[N][N];
	for (i = 0;i < N;i++)
	{
		s[i][i] = 1;
		s[i][0] = 1;
	}
	for (i = 2;i < N;i++)
		for (j = 1;j <= i - 1;j++)
			s[i][j] = s[i - 1][j - 1] + s[i - 1][j];
	for (i = 0;i < N;i++)
	{
		for (j = 0;j <=i;j++)
			printf("%5d", s[i][j]);
		printf("\n");
	}
	printf("\n");
	getchar();
	return 0;
}