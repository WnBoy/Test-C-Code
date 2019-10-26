#include<stdio.h>
long fact(int);
long rfact(int);
int main(void)
{
	int num;
	printf("Enter a number:");
	while (scanf("%d", &num) == 1)
	{
		if (num < 0)printf("数太小了\n");
		else if (num > 12)printf("数太大了\n");
		else
		{
			printf("fact=%ld\n", fact(num));
			printf("rfact=%ld\n", rfact(num));
		}
		printf("Enter a number:");
	}
	getchar();
	return 0;
}
long fact(int n)
{
	int m;
	for (m = 1;n > 1;n--)
		m *= n;
	return m;
}
long rfact(int n)
{
	int m;
	if (n == 0)m = 1;
	else m = n*rfact(n - 1);
	return m;
}