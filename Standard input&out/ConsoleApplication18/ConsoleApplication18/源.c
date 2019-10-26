#include<stdio.h>
int main()
{
	int i, j, s[100];
	for (i = 0;i < 100;i++)
		s[i] = i + 1;
	printf("%5d%5d", s[0], s[1]);
	for (i = 2;i < 100;i++)
	{
		for (j = 2;j <= s[i] - 1;j++)
		{
			if (s[i] % j == 0)
				break;
		}
		if (j >= s[i])
			printf("%5d", s[i]);
	}
	printf("\n");
	getchar();
	return 0;
}