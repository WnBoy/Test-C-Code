#include<stdio.h>
int main()
{
	int s[15][15], i, j, k, n;
	printf("please input a number1--15:\n");
	scanf("%d", &n);
	for (i = 1;i <= 15;i++)
		for (j = 1;j <= 15;j++)
			s[i][j] = 0;
	j = n / 2 + 1;
	s[1][j] = 1;
	for (k = 2,i=1;k <= n*n;k++)
	{
		i = i - 1;
		j = j + 1;
		if (i<1 && j>n)
		{
			i = i + 2;
			j = j - 1;
		}
		else
		{
			if (i < 1)i = n;
			if (j > n)j = 1;
		}
		if (s[i][j] == 0)
			s[i][j] = k;
		else
		{
			i = i + 2;
			j = j - 1;
			s[i][j] = k;
		}
	}
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
			printf("%d", s[i][j]);
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}