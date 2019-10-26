#include<stdio.h>
int main(void)
{
	int n, m=0;
	int i, j;
	int flag=1;
	printf("please input a number:");
	scanf("%d", &n);
	for (i = 2;i <= n;i++)
		{
		for (j = 2;j*j <= i;j++)
		{
			if (i%j == 0)
			{
				flag = 0;
				break;
			}
			else flag = 1;
		}
		if (flag)
			printf("%3d", i);
		}
	getchar();
	getchar();
	return 0;
}