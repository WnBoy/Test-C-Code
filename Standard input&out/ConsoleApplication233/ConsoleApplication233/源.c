#include<stdio.h>
#include<stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int main(void)
{
	struct book library[MAXBKS];
	int count=0;
	int index, filecount;
	FILE*fp;
	int size = sizeof(struct book);
	while ((fp = fopen("book.dat", "a+b")) == NULL)
	{
		puts("Open file is failure!");
		exit(1);
	}
	rewind(fp);
	while (count < MAXBKS&&fread(&library[count], size, 1, fp) == 1)
	{
		if (count == 0)puts("Current contents of book.dat:");
		printf("%s by %s:$ %.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS) {
		puts("The book.dat file is full!");
		exit(2);
	}
	puts("Please add new book titles.");
	while (count < MAXBKS&&gets(library[count].title) != NULL&&library[count].title[0] != '\0')
	{
		puts("Please add new author:");
		gets(library[count].author);
		puts("Please add new value:");
		scanf("%f", &library[count].value);
		while (getchar() != '\n')
			continue;
		if(count<MAXBKS)
			puts("Please add new book titles.");
	}
	if (count > 0)
	{
		puts("Here is the list of your books:");
		for (index = 0;index < count;index++)
		{
			printf("%s by %s:$%.2f\n", library[index].title, library[count].author, library[count].value);
		}
		fwrite(&library[filecount], size, count - filecount, fp);
	}
	else
		puts("No books.");
	puts("Bye!");
	fclose(fp);
	getchar();
	return 0;
}