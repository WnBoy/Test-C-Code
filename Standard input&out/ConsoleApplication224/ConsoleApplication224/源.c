#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(void)
{
	char ch;
	char t;
	FILE *fs, *fd;
	char s[20];
	char d[20];
	puts("Please enter source file:");
	gets(s);
	while ((fs = fopen(s, "r") )== NULL)
	{
		fprintf(stderr, "Open file s fault£¡");
		exit(1);
	}
	puts("Please enter d file:");
	gets(d);
	while ((fd = fopen(d, "w")) == NULL)
	{
		fprintf(stderr, "Open file d fault!");
		exit(2);
	}
	while ((ch = getc(fs)) != EOF)
	{
		putc(toupper(ch), fd);
	}
	fclose(fs);
	fclose(fd);

	getchar();
	return 0;
}