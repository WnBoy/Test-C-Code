#include<stdio.h>
int main()
{
	int gg(int month, int day);
	int bb(int year);
	int year, month, day,t;
	printf("please into:");
	scanf("%d,%d,%d", year, month, day);
	t = gg(month, day);
	if (bb(year)&&t>=3)
		t = t + 1;
	printf("%d", t);
	getchar();
	getchar();
	return 0;
}
int gg(int month, int day)
{
	int s[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i;
	for (i = 0;i < month;i++)
		day+=s[i];
	return(day);
}
int bb(int year)
{
	int leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	return(leap);
}