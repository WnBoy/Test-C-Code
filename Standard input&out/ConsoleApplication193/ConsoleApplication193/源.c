#include<stdio.h>
int main(void)
{
	int n;
	n = gg();
	printf("%d\n", n);
	getchar();
	getchar();
	return 0;

}

int gg(void)
{
	int m;
	printf("Please enter a number:");
	while (scanf("%d", &m) != 1)
	{
		scanf("%*s");
		printf("Please enter a number:");
	}
	return m;
}