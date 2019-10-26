#include<stdio.h>
#include<string.h>
int main()
{
	void gg(char c[10]);
	char s[10];
	printf("please inter four number:");
	gets(s);
	gg(s);
	getchar();
	return 0;
	
}
void gg(char c[10])
{
	int i;
	for (i = strlen(c);i>0;i--)
	{
		c[2*i] = c[i];
		c[2*i-1] = ' ';
	}
	printf("%s", c);
}