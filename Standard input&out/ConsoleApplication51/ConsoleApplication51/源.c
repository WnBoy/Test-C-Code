#include<stdio.h>
int main()
{
	int lenth(char *p);
	int len;
	char s[10];
	printf("please enter string:\n");
	scanf("%s", s);
	len=lenth(s);
	printf("The string len is:%d\n", len);
	getchar();
	getchar();
	return 0;
}
int lenth(char *p)
{
	int i;
	for (i = 0;i < 10;i++)
		if (*(p + i) == '\0')break;
	return(i);
}