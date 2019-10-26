#include<stdio.h>
int main()
{
	char c;
	for (;(c = getchar()) != '\n';)
		printf("%c", c);
	getchar();
	return 0;
}