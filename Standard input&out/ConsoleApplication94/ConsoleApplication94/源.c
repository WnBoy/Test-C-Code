#include<stdio.h>
int main(void)
{
	int n = 0;
	size_t intsize;
	intsize = sizeof(int);
	printf("n=%d,n hase %zd byte;all ints have %zd byte.\n", n, sizeof n, intsize);
	getchar();
	return 0;
}