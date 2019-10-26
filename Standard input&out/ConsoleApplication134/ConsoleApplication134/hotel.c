#include<stdio.h>
#include"hotel.h"
int menu(void)
{
	int code, status;
	printf("\n%s%s\n", STARS, STARS);
	printf("请输入一个数字：\n");
	printf("1)F 2)O\n");
	printf("3)C 4)S\n");
	printf("5)Quit\n");
	printf("\n%s%s\n", STARS, STARS);
	while (status = scanf("%d", &code)!=1 || (code < 1 || code>5))
	{
		if (code != 1)scanf("%*s");
		printf("请输入一个数字：\n");
	}
	return code;
}
int getnights(void)
{
	int nights;
	printf("请输入住的时间：");
	while (scanf("%d", &nights) != 1)
	{
		scanf("%*s");
		printf("请输入住的时间：");
	}
	return nights;
}
void showprice(double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;
	for (n = 1;n <= nights;n++, factor *= DISCOUNT)
		total += rate*factor;
	printf("这个旅馆总共花费%0.2f元！\n", total);
}