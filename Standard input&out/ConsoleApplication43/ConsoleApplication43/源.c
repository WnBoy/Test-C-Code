#include<stdio.h>
int main()
{
	void mua(int s[10], int n);
	int i, a[10];
	int *p=a;
	printf("please enter ten number:");
	for (i = 0;i < 10;i++)
		scanf("%d", p++);
	p = a;
	mua(p, 10);
	for (p = a, i = 0;i < 10;i++)
		printf("%3d", *p++);
	printf("\n");
	getchar();
	getchar();
	return 0;
}
void mua(int *s, int n)
{
	int *i, *j, t, *k;
	for (i = s;i <=s+n-1;i++)
	{
		k = i;
		for (j = i + 1;j <=s+n;j++)
			if (*j > *k)k = j;
		if (i != k)
		{
			t = *k;
			*k=*i;
			*i = t;
		}
	}

}