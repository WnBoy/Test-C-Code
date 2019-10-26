#include<stdio.h>
int main(void)
{
	int a = 100;
	printf("a=%d,a=%o,a=%x\n", a, a, a);
	printf("a=%d,a=%#o,a=%#x", a, a, a);
	getchar();
	return 0;
}