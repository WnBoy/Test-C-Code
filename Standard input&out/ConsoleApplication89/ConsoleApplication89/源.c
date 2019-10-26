#include<stdio.h>
int max(int a, int b, int c);
int Maxsubsum(const int a[], int left, int right);
int main()
{
	int a[8], M, i;
	printf("please enter num:");
	for (i = 0;i < 8;i++)
		scanf("%d", &a[i]);
	M=Maxsubsum(a, 0, 7);
	printf("M=%d", M);
	getchar();
	getchar();
	return 0;
}
int Maxsubsum(const int a[], int left, int right)
{
	int maxleftsum, maxrightsum;
	int maxbordleftsum=0, maxbordrightsum=0;
	int bordleftsum=0, bordrightsum=0;
	int center, i;
	if (left == right)
	{
		if (a[left] > 0)return a[left];
		else
			return 0;
	}
	center = (left + right) / 2;
	maxleftsum = Maxsubsum(a, left, center);
	maxrightsum = Maxsubsum(a, center + 1, right);
	for (i = center;i >= left;i--)
	{
		bordleftsum += a[i];
		if (bordleftsum > maxbordleftsum)
			maxbordleftsum = bordleftsum;
	}
	for (i = center+1;i < right;i++)
	{
		bordrightsum += a[i];
		if (bordrightsum > maxbordrightsum)
			maxbordrightsum = bordrightsum;
	}
	return(max(maxleftsum, maxrightsum, maxbordleftsum + maxbordrightsum));
}
int max(int a, int b, int c)
{
	int t=a;
	if (b >= t)t = b;
	if (c >= t)t = b;
	return t;
}