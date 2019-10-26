#include<stdio.h>
int main()
{
	void gg(int s[3][3]);
	int s[3][3];
	int i, j;
	printf("please enter a number:\n");
	for (i = 0;i <= 2;i++)
		for (j = 0;j <= 2;j++)
			scanf("%d", &s[i][j]);
	printf("zhengcahngdde\n");
	for (i = 0;i <= 2;i++)
	{
		for (j = 0;j <= 2;j++)
			printf("%5d", s[i][j]);
		printf("\n");
	}
	gg(s);
	printf("daohuolaide\n");
	for (i = 0;i <= 2;i++)
	{
		for (j = 0;j <= 2;j++)
			printf("%5d", s[i][j]);
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}
void gg(int s[3][3])
{
	int k, n, t;
	for (k = 0;k <= 2;k++)
		for (n = 0;n <= 2;n++)
		{
			t = s[n][k];
			s[n][k] = s[k][n];
			s[k][n] = t;
		}
}