#include<stdio.h>
#include<ctype.h>
#define n 20
void gg(char *strs);
int main(void)
{
	char str[n];
	int i;
	printf("please enter a strings:\n");
	gg(str);
	puts(str);
	getchar();
	return 0;
}
void gg(char *strs)
{
	int j;
	for (j = 0;j < n;j++)
	{
		*(strs+j) = getchar();
		if (isspace(*(strs + j)))break;
	}
	*(strs + j) = '\0';
}