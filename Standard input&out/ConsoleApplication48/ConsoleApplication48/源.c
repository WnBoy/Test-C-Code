#include<stdio.h>
int main()
{
	void inv(int *x, int n);
	int i, a[10] = { 3,7,5,6,8,2,4,6,8,2 };
	printf("gg:");
	for (i = 0;i < 10;i++)
		printf("%3d", a[i]);
	printf("\n");
	inv(a, 10);
	printf("mm:");
	for (i = 0;i < 10;i++)
		printf("%3d", a[i]);
	printf("\n");
	getchar();
	return 0;

}
void inv(int *x,int n)
{
	int *i, *p, *j, temp, m = (n - 1) / 2;
	i = x;j = x + n - 1 ;p = x + m;
	for (;i <= p;i++,j++)
	{
		temp = *i;*i = *j;*j = temp;
	}

}