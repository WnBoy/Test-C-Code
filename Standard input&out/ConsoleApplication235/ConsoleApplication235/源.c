#include<stdio.h>
void display(struct demo*p);
struct name {
	char first[10];
	char mediaem[10];
	char last[10];
};

struct demo {
	int number;
	struct name nemed;
};

struct demo persons[5]={
	{ 1253656,{ "sda","asdjlas","widy" } },
	{ 3898456,{ "sajkj","shak","ask" } },
	{ 1586653,{ "sjaa","asdals","askda" } },
	{ 8686463,{ "ashk","askh","asak" } },
	{ 3535129,{ "sah","saja","ashka" } }
};

int main(void)
{
	display(persons);
	getchar();
	return 0;
}

void display(struct demo*p)
{
	int index;
	for (index = 0;index < 5;index++)
	{
		if (p[index].nemed.mediaem != '\0')
			printf("%s   %s   %c. %d\n",
				p[index].nemed.first, p[index].nemed.last, p[index].nemed.mediaem[0], p[index].number);
		else
			printf("%s   %s   %d\n", p[index].nemed.first, p[index].nemed.last, p[index].number);
	}
}