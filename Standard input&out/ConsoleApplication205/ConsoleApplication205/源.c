#include<stdio.h>
#include<string.h>
void input(char*s);
int main(void)
{
	char str[50];
	int l;
	puts("Please input string:");
	input(str);
	l = strlen(str);
	str[l] = '\0';
	puts(str);
	getchar();
	getchar();
	getchar();
	return 0;
}

void input(char*s)
{
	scanf("%s", s);
}