#include<stdio.h>
void dd(char*s);
int main(void)
{
	char str[50];
	puts("please enter str:");
	gets(str);
	while (*str != 'q')
	{
		dd(str);
		putchar('\n');
		puts("Please continue enter str except q:");
		puts("please enter str:");
		gets(str);
	}
	getchar();
	return 0;
}

void dd(const char*s)
{
	char*t = s;
	while (*s != '\0')
		s++;
	while (s > t)
		putchar(*--s);
}