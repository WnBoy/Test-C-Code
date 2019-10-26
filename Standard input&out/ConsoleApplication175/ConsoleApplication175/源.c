#include<stdio.h>
int main(void)
{
	int older;
	long long n;
	scanf("%d", &older);
	n = older * 12 * 30 * 24 * 60 * 60;
	printf("%lld", n);
	getchar();
	getchar();
	return 0;
}