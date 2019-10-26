#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char ch;
	ch = getchar();
	if (islower(ch))
		putchar(ch);
	else
		printf("NONNONO");
	return 0;
}