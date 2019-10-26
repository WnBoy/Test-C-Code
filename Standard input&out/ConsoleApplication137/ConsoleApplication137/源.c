#include<stdio.h>
void input(char, int, int);
int main()
{
	int n=3, m=4;
	char c = '*';
	input(c, n, m);
	getchar();
	return 0;
}
void input(char ch, int n, int m)
{
	int i, j;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= m;j++)
			putchar(ch);
		putchar('\n');
	}
}