#include<stdio.h>
int main()
{
	int a, b, c, max, temp;
	scanf("%d,%d,%d", &a, &b, &c);
	temp = (a > b) ? a : b;
	max = (temp > c) ? temp : c;
	printf("%d\n", max);
	getchar();
	return 0;
	
}