#include<stdio.h>
void get(double(*p)[5]);
double ave(double(*s)[5]);
double aave(double(*w)[5]);
double max(double(*y)[5]);
int main(void)
{
	int k;
	double d[3][5];
	get(d);
	for (k = 0;k < 3;k++)
		printf("ave %d is %5.2f\n", k, ave(d + k));
	printf("All ave is:%5.2f\n",aave(d));
	printf("max is %5.2f", max(d));
	getchar();
	getchar();
	return 0;

}

void get(double (*p)[5])
{
	printf("Please enter number:\n");
	int i, j;
	for(j=0;j<3;j++)
		for (i = 0;i < 5;i++)
			scanf("%lf", &p[j][i]);
	return;
}

double ave(double(*s)[5])
{
	int i;
	double sum=0;
	for (i = 0;i < 5;i++)
		sum += *(*s + i);
	return sum / 5;
}

double aave(double(*w)[5])
{
	double sum=0;
	int i, j;
	for (i = 0;i < 3;i++)
		for (j = 0;j < 5;j++)
			sum += w[i][j];
	return sum / 15;
}

double max(double(*y)[5])
{
	double m = y[0][0];
	int i, j;
	for (i = 0;i < 3;i++)
		for (j = 0;j < 5;j++)
			if (y[i][j] > m)
				m = y[i][j];
	return m;
}