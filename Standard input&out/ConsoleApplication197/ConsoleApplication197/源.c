#include<stdio.h>
copy_arr(double s[5], double t1[5], int n);
copy_prr(double *s, double *t2, int m);
int main(void)
{
	int i;
	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[5];
	double target2[5];
	copy_arr(source, target1, 5);
	copy_prr(source, target2, 5);
	for (i = 0;i < 5;i++)
	{
		printf("%5.1f", source[i]);
	}
	putchar('\n');
	for (i = 0;i < 5;i++)
	{
		printf("%5.1f", target1[i]);
	}
	putchar('\n');
	for (i = 0;i < 5;i++)
	{
		printf("%5.1f", target2[i]);
	}
	putchar('\n');
	getchar();
	return 0;
}

copy_arr(double s[5], double t1[5], int n)
{
	int j;
	for (j = 0;j < 5;j++)
		t1[j] = s[j];
	return;
}

copy_prr(double *s, double *t2, int m)
{
	int j;
	for (j = 0;j < 5;j++)
		*t2++ = *s++;
	return;
}