#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE*fp;
	char name[50];
	char out[50];
	long pos;
	char ch;
	int k=0;
	int i;
	puts("Please enter name:");
	gets(name);
	while ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "open file fault!");
		exit(1);
	}
	puts("Please enter i:");
	while (scanf("%d", &i) != 1)
	{
		pos = (long)i * sizeof(long);
		fseek(fp, pos, SEEK_SET);
		fscanf(fp, "%s", out);
		while (out[k] != '\n')
			putchar(out[k++]);
	}
	fclose(fp);
	getchar();
	return 0;
}