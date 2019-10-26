#include<stdio.h>
#include<string.h>
char*strncpy(char*s1, char*s2, int n);
int main(void)
{
	int n;
	char*op;
	char str1[50], str2[50];
	op = str1;
	puts("Please enter strings:");
	gets(str2);
	scanf("%d", &n);
	op=strncpy(str1, str2, n);
	puts(op);
	getchar();
	getchar();
	return 0;
}

char*strncpy(char*s1, char*s2, int n)
{
	int i, t;
	t = strlen(s2);
	if (t < n)
		for (i = 0;i < t;i++)
			s1[i] = s2[i];
	else
		for (i = 0;i < n;i++)
			s1[i] = s2[i];
	s1[i] = '\0';
	return s1;
}