#include<stdio.h>
#define TSIZE 45
struct film {
	char title[TSIZE];
	int rating;
};
int main(void)
{
	int n, j, i = 0;
	struct film*movies;
	printf("Enter the maximum number of movies you'll enter:\n");
	scanf("%d", &n);
	while (getchar() != '\n')
		continue;
	movies = (struct film*)malloc(n * sizeof(struct film));
	puts("Enter first movie title:");
	while (i < n&&gets(movies[i].title) != NULL&&movies[i].title != '\0')
	{
		puts("Enter your rating<0-10>");
		scanf("%d", &movies[i++].rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop):");
	}
	if (i == 0)
		printf("No date entered");
	else
		printf("Here is the movie list:\0");
	for (j = 0;j < i;j++)
		printf("Movie is:%s Rate is: %d\n", movies[j].title, movies[j].rating);
	printf("Bye!\n");
}