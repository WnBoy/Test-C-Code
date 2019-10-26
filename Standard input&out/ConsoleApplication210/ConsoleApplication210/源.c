#include<stdio.h>
char*string_in(char*s1, char*s2);
int main(void)
{
	char str1[50], str2[50];
	char *p;
	puts("please enter str1:");
	gets(str1);
	while (*str1 != 'q')
	{
		puts("please enter str2:");
		gets(str2);
		p = string_in(str1, str2);
		if (p)
		{
			puts("Find!");
			puts(p);
		}
		else
			puts("no find!");
		puts("please continue enter except q");
		puts("please enter str1:");
		gets(str1);
	}
	puts("quit");
	getchar();
	return 0;
}

char*string_in(char*s1, char*s2)
{
	char*save_s1 = s1;
	char*save_s2 = s2;
	if (*s1 == '\0' || *s2 == '\0')return NULL;
	while (1)
	{
		if (*s1 == *s2)
		{
			if (*++s1 == '\0')return NULL;
			if (*++s2 == '\0')return save_s1;
		}
		else
		{
			if (*++s1 == '\0')return NULL;
			save_s1 = s1;
			s2 = save_s2;
		}
	}
}