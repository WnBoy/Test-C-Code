#include<stdio.h>
void mm(char c, int i, int j);
int main(void)
{
	char c;
	int i, j;
	printf("Please enter:");
	c = getchar();
	scanf("%d%d", &i, &j);
	mm(c, i, j);
	getchar();
	getchar();
	return 0;
}

void mm(char c, int i, int j)
{
	int k, r;
	for (k = 1;k <= j;k++)
	{
		for (r = 1;r <= i;r++)
			putchar(c);
		putchar('\n');
	}
	
	return;
}