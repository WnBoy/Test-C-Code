#include<stdio.h>
double min(double x, double y);
int main(void)
{
	double a, b;
	printf("please enter two double number:");
	scanf("%lf%lf", &a, &b);
	printf("%.2f\n", min(a, b));
	getchar();
	getchar();
	return 0;
}

double min(double x, double y)
{
	return(x > y) ? y : x;
	 
}