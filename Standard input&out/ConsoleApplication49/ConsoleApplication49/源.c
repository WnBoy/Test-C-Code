#include<stdio.h>
int main()
{
	void input(int *s);
	void sort(int *p);
	void output(int *r);
	int a[10];
	input(a);
	sort(a);
	output(a);
	getchar();
	getchar();
	return 0;
}
void input(int *s)
{
	printf("please input 10 number:");
	int i;
	for (i = 0;i < 10;i++)
		scanf("%d", s + i);
}
void sort(int *p)
{
	int i, *min, *max, t;
	min = max = p;
	for (i = 1;i < 10;i++)
	{
		if (*(p + i) > * max)
			max = p + i;
		else if (*(p + i) < min)
			min = p + i;
	}
		t = *p;*p = *min;*min = t;
		if (max == p)max = min;
		t = *(p + 9);*(p + 9) = *max;*max = t;
}
void output(int *r)
{
	int *i;
	printf("Now is:");
	for (i = r;i < r+10;i++)
		printf("%3d", *i);
}