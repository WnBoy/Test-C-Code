#include<stdio.h>
static int mode;
static double distance;
static double fuel;
void set_mode(extern int m)
{
	mode = m;
	if (m > 1)
	{
		mode = 1;
		printf("Invalid mode specified.Mode %d (US) used.", mode);
	}
	if(m<0)
	{
		mode = 0;
		printf("Invalid mode specified.Mode %d (metric) used.", mode);
	}
}
void get_info(void)
{
	printf("Enter distance traveled in kilometer:");
	scanf("%lf", &distance);
	printf("Enter fule consumed in liters:");
	scanf("%lf", &fuel);
}
void show_info(void)
{
	double t;
	if (mode == 0)
	{
		t = fuel / distance;
		t *= 100;
		printf("Fuel consumption is %4.2lf liters per 100km.\n", t);
	}
	if(mode==1)
	{
		t = distance / fuel;
		printf("Fuel consumption is %3.1lf miles per gallon.\n", t);
	}
}