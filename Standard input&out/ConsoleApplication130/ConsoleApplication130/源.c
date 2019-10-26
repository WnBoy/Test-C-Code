#include<stdio.h>
void gg(int);
int main(void)
{
	gg(1);
	return 0;
}
void gg(int n)
{
	printf("%d\n", n);
	if (n < 4)gg(n+1);
	printf("%d", n);
}