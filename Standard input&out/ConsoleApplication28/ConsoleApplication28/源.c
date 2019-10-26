#include<stdio.h>
int main()
{
	int n;
	printf("please input a number:");
	scanf("%d", n);
	if (sou(n))
		printf("NO\n");
	else
		printf("yeas\n");
	getchar();
	
	return 0;

}
int sou(int x)
{
	int i;
	for (i = 2;i <= x - 1;i++)
		if (x%i == 0)break;
	if (i >= x)
		return 1;
	else
		return 0;
}