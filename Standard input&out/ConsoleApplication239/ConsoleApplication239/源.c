#include<stdio.h>
#include<stdlib.h>
#define NUM 40
void filltt(double*ptr, int n);
void showtt(double*ptr, int m);
int com(const void*pt1, const void*pt2);
int main(void)
{
	double tt[NUM];
	filltt(tt,NUM);
	puts("Random list:");
	showtt(tt,NUM);
	qsort(tt, NUM, sizeof(double), com);
	puts("\nSort list:");
	showtt(tt,NUM);
	getchar();
	return 0;
}

void filltt(double*ptr,int n)
{
	int i;
	for (i = 0;i < NUM;i++)
		ptr[i] = (double)rand() / ((double)rand() + 1);
}
void showtt(double*ptr, int m)
{
	int i;
	for (i = 0;i < NUM;i++)
	{
		printf("%f", ptr[i]);
		if (i % 6 == 5)putchar('\n');
	}
	if (i % 6 != 0)
		putchar('\n');
}

int com(const void*pt1, const void*pt2)
{
	const double*a1 = (const double *)pt1;
	const double*a2 = (const double *)pt2;
	if (*a1 > *a2)return 1;
	else if (*a1 == *a2)return 0;
	else return -1;
}