#include<stdio.h>
#include<string.h>
char*string_in(char*s1, char*s2);
int main(void)
{
	char*t;
	char str1[50];
	char str2[50];
	t = str1;
	puts("Please input str1:");
	gets(str1);
	puts("Please input str2:");
	gets(str2);
	t=string_in(str1, str2);
	puts(t);
	getchar();
	getchar();
	return 0;
}

char*string_in(char*s1, char*s2)
{
	char*r;
	unsigned int k;
	for (k = 0;k < strlen(s1);k++)
		if (*(s1 + k) == *(s2 + k))
		{
			break;
			r = s1 + k;
		}
		else r = NULL;
	return r;
}