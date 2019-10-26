#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int ch;
	FILE*fp;
	long count = 0;
	char name[20];
	fprintf(stdout, "PLease enter name:");
	scanf("%s", name);
	while ((fp = fopen(name, "r") == NULL))
	{
		fprintf(stderr, "open file fault!");
			exit(1);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	fprintf(stdout, "File %s has %ld charters\n", name, count);
	getchar();
	return 0;
}