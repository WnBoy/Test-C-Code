#include<stdio.h>
int main(void)
{
	int current = 100;
	int i;
	for (i = 1;current > 0;i++)
	{
		current = current*(1 + 0.08);
		current = current - 10;
	}
	printf("%d", i);
	getchar();
	return 0;
}