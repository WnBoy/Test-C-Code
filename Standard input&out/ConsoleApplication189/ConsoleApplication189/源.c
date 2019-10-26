#include<stdio.h>
#define ave 10
int main(void)
{
	int time;
	double wage, jsalary, tax;
	printf("Please enter your work times:");
	while (scanf("%d", &time) == 1)
	{
		if (time <= 40)wage = 10 * time;
		else wage = 10 * 1.5*time;
		if (wage <= 300)tax = wage*0.15;
		else
		{
			if (wage <= 450)tax = 300 * 0.15 + (wage - 300)*0.2;
			else tax = 300 * 0.15 + 150 * 0.2 + (wage - 450)*0.25;
		}
		jsalary = wage - tax;
		printf("wage=%f\ttax=%f\tjsalary=%f\n", wage, tax, jsalary);
		printf("Please enter your work times:");
	}
	getchar();
	getchar();
	return 0;
}