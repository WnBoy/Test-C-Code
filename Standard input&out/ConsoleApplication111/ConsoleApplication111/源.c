#include<stdio.h>
#define basesalary 10
#define addtime 1.5
#define first 0.15
#define second 0.2
#define others 0.25
int main(void)
{
	int time;
	double sumsalary=0,tax=0, salary=0;
	printf("please input time:");
	scanf("%d", &time);
	if (time <= 40)sumsalary = basesalary*time;
	else sumsalary = basesalary*addtime*time;
	if (sumsalary <= 300)tax = sumsalary*first;
	else
		if (sumsalary <= 450)tax = 300 * first + (sumsalary - 300)*second;
		else tax = 300 * first + 150 * second + (sumsalary - 450)*others;
	salary = sumsalary - tax;
	printf("sumsalary=%f\ntax=%f\nsalary=%f", sumsalary, tax, salary);
	getchar();
	getchar();
	return 0;
}