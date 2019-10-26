#include<stdio.h>
#define MAXTITL 40
#define MAXAUTL 30
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library;
	puts("Please enter title:");
	gets(library.title);
	puts("Please enter author:");
	gets(library.author);
	puts("Please enter value:");
	scanf("%f", &library.value);
	printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
	puts("Done.");
	getchar();
	getchar();
	return 0;
}