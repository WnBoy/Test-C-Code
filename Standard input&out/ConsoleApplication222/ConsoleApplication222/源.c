#include<stdio.h>
#include<stdlib.h>
#define MAX 40
int main(void)
{
	FILE*fp;
	char words[MAX];
	if ((fp = fopen("words.dat", "a+")) == NULL)
	{
		fprintf(stdout, "can not open\"wods.dat\"file.");
		exit(1);
	}
	puts("Enter words to add to the file;press the Enter");
	puts("key at the begining of a line to determine.");
	while (gets(words) != NULL&&words[0] != '\0')
		fprintf(fp, "%s", words);
	puts("file content:");
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1)
		puts(words);
	fclose(fp);
	getchar();
	return 0;
}