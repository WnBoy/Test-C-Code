#include<stdio.h>
int main()
{
	int i, j, t;
	for (i = 1;i <= 4;i++)
	{
		for (j = 1;j <= 5; j++)
		{
			t = i*j;
			printf("%5d", t);
		}
		printf("\n");
	}
	printf("\n");
	getchar();
	return 0;
}