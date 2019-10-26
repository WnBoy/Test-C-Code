#include<stdio.h>
#include<string.h>
struct namect getinfo(void);
struct namect makeinfo(struct namect s);
void putinfo(const struct namect s);
struct namect
{
	char first[50];
	char last[50];
	int letters;
};
int main(void)
{
	struct namect person;
	person=getinfo();
	person=makeinfo(person);
	putinfo(person);
	getchar();
	return 0;
}

struct namect getinfo(void)
{
	struct namect s;
	puts("Please enter first name:");
	gets(s.first);
	puts("Please enter last name:");
	gets(s.last);
	return s;
}

struct namect makeinfo(struct namect s)
{
	s.letters = strlen(s.first) + strlen(s.last);
	return s;
}

void putinfo(const struct namect s)
{
	printf("%s %s,your name contain %d letters.\n", s.first, s.last, s.letters);
}