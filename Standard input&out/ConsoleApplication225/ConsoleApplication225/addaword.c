#include<stdio.h>
#include<stdlib.h>;
int main(void)
{
	FILE*fp;
	char word[50];
	while ((fp = fopen("word", "a+")) == NULL)
	{
		fprintf(stderr, "open file fault!");
		exit(1);
	}
	puts("please enter words:");
	while (gets(word) != NULL&&word[0] != '\0')
	{
		fprintf(fp, "%s", word);
	}
	rewind(fp);
	while (fscanf(fp, "%s", word) == 1)
	{
		puts(word);
	}
	fclose(fp);

	getchar();
	return 0;
}