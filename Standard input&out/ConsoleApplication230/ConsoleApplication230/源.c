#include<stdio.h>
struct funds {
	char bank[30];
	double bankfund;
	char save[30];
	double savefund;
};
double sum(const struct funds s);
int main(void)
{
	struct funds stan = {
		"sjdaldj",
		30.25,
		"dhakljdslas",
		16.15
	};
	printf("total is:$%.2f.\n", sum(stan));
	getchar();
	return 0;
}

double sum(const struct funds s)
{
	return (s.bankfund + s.savefund);
}