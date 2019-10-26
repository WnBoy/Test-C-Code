#include<stdio.h>
#include<stdbool.h>
#include<string.h>
_Bool is_within(char c, char*str);
int main(void)
{
	_Bool p;
	char cc;
	char str[50];
	puts("Please enter a char and strings:");
	cc = getchar();
	getchar();
	gets(str);
	p=is_within(cc, str);
	if (p)puts("yes");
	else puts("no");
	getchar();
	return 0;
}

_Bool is_within(char c, const char*str)
{
	_Bool r;
	int k,l;
	l = strlen(str);
	for (k = 0;k < l;k++)
	{
		if (c == str[k])
		{
			r = true;
			break;
		}
		else r = false;
	}
		return r;
}