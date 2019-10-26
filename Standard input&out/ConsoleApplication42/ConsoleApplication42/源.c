#include<stdio.h>
int main()
{
	void gg(int *c1, int n);
	int a[10] = { 3,5,2,7,3,6,3,8,4,8 };
	int *p = a;
	printf("The original array:\n");
	for (;p < (a + 10);)
		printf("%d", *p++);
	p = a;
	gg(p, 10);
	for (p = a;p < a + 10;p++)
		printf("%d", *p);
	getchar();
	return 0;
}
void gg(int *c1, int n)
{
	int *p, *i, *j, t, m = (n - 1) / 2;
	i = c1;
	j = c1 + n - 1;
	p = m + c1;
	for (i = 0;i <= p;i++,j--)
	{
		t = *i;
		*i = *j;
		*j = t;
	}
}