#include<stdio.h>
int main()
{
	int i, sum;
	i = 1;
	sum = 0;
	while (i <= 100)
	{
		sum = sum + i;
		i++;
	}
	printf("%d\n", sum);
	getchar();
	return 0;
}