#include<stdio.h>
char *search(char *str, char c);
int main(viod)
{
	char ch;
	char *p=NULL;
	char strs[50];
	printf("pleaase enter char and strings:\n");
	ch=getchar();
	getchar();
	gets(strs);
	p=search(strs, ch);
	if (p)printf("yes!!!");
	else printf("no!!!");
	getchar();
	return 0;
}
char *search(char *str, char c)
{
	int i;
	char *p=NULL;
	for (;*str != '\0';str++)
		if (*str == c)
		{
			p = str;
			break;
		}
		return p;
}