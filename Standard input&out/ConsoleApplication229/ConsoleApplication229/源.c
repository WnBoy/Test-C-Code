#include<stdio.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int main(void)
{
	struct book library[MAXAUTL];
	int count=0;
	int index=0;
	puts("Please enter:");
	while (count < MAXBKS&&gets(library[count].title) != NULL&&library[count].title[0] != '\0')
	{
		puts("Please enter authou:");
		gets(library[count].author);
		puts("please enter value:");
		scanf("%f", &library[count++].value);
		getchar();
		if (count < MAXAUTL)
			puts("Enter the next title:");
	}
	printf("Here is these books:");
	while (index < count)
	{
		printf("%s by %s :$%.2f\n", library[index].title, library[index].author, library[index].value);
		index++;
	}

	getchar();
	return 0;
}