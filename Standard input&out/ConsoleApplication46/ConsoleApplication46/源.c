#include<stdio.h>
int main()
{
	void gg(int *p1, int *p2);
	int *p1, *p2, *p3;
	int n1, n2, n3;
	printf("Please input three number:\n");
	scanf("%d,%d,%d", &n1, &n2, &n3);
	p1 = &n1;
	p2 = &n2;
	p3 = &n3;
	if (n1 > n2)gg(p1, p2);
	if (n1 > n3)gg(p1, p3);
	if (n2 > n3)gg(p2, p3);
	printf("%5d%5d%5d\n", n1, n2, n3);
	getchar();
	getchar();
	return 0;
}
void gg(int *p1, int *p2)
{
	int t;
	t = *p1;
	*p1 = *p2;
	*p2 = t;
}