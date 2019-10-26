#include<stdio.h>
double mm(double n1, double n2);
int main(void)
{
	double n1, n2;
	printf("Please enter two number:");
	scanf("%lf%lf", &n1, &n2);
	printf("%.2lf",mm(n1, n2));
	getchar();
	getchar();
	return 0;
}

double mm(double n1, double n2)
{
	double t;
	t = 2 / (1 / n1 + 1 / n2);
	return t;
}