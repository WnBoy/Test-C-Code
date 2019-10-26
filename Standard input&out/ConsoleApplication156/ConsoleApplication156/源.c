#include<stdio.h>
#include<stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE*pbooks;
	int size = sizeof(struct book);
	if ((pbooks = fopen("book.dat", "a+b")) == NULL)
	{
		fputs("Cant't open book.dat file\n", stderr);
		exit(1);
	}
	rewind(pbooks);
	while (count < MAXBKS&&fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("Current countents of book.dat");
		printf("%s by %s:$%.2f\n", library[count].author, library[count].title, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("The book.dat is full.\n",stderr);
		exit(2);
	}
	puts("please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	while (count < MAXBKS&&gets(library[count].title) != NULL&&library[count].title[0] != '\0')
	{
		puts("Now enter author.");
		gets(library[count].author);
		puts("Now enter the value.");
		scanf("%f", library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)puts("Enter the next title.");
	}
	if (count > 0)
	{
		puts("Here is the list of your books:");
		for (index = 0;index < count;index++)
			printf("%s by %s:$%.2f\n", library[index].author, library[index].title, library[index].value);
		fread(&library[count], size, count - filecount, pbooks);
	}
	else
		puts("No books?Too bad.\n");
	puts("Bye.");
	fclose(pbooks);
	return 0;
}
