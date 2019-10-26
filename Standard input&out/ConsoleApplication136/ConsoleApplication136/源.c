#include<stdio.h>
void change(int*, int*);
int main(void)
{
	int a=5, b=10;
	printf("原始的a=%d  b=%d\n",a, b);
	change(&a, &b);
	printf("现在的a=%d  b=%d\n", a, b);
	getchar();
	return 0;
}
void change(int*n, int*m)
{
	int t;
	t = *n;
	*n = *m;
	*m = t;
}