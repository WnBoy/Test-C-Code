#include<stdio.h>
int main()
{
	int n, i;
	printf("please enter a number:");
	scanf("%d", &n);
	for (i = 2;i <= n - 1;i++)
	{
		if (n%i == 0)break;
	}
	if (i < n)
		printf("NO");
	else
		printf("YES");
	getchar();
	getchar();
	return 0;

}