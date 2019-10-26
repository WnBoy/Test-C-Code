#include<stdio.h>
int main(void)
{
	int i, j;
	char lets[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (i = 1;i <= 6;i++)
	{
		int n = 5;
		for (j = 1;j <= i;j++, n--)
			printf("%c",lets[n]);
		putchar('\n');
	}
	getchar();
	return 0;
}