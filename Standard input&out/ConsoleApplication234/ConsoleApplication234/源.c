#include<stdio.h>
int days(int day, int mon, int year);
int leap(int year);
struct month {
	char name[10];
	char abbrev[4];
	int days;
	int monumb;
};
struct month months[12]={
	{"january", "jan", 31, 1},
	{ "february","feb",28,2 },
	{ "march","mar",31,3 },
	{ "april","apr",30,4 },
	{ "may","may",31,5 },
	{ "june","jun",30,6 },
	{ "july","jul",31,7 },
	{ "argust","aug",31,8 },
	{ "september","sep",30,9 },
	{ "october","oct",31,10 },
	{ "novermber","nov",30,11 },
	{ "december","dec",31,12 }
};
int main(void)
{
	int day, mon, year, daytotal;
	puts("Pleaase enter year,month and days:");
	while (scanf("%d%d%d", &day, &mon, &year) == 3)
	{
		daytotal = days(day, mon, year);
		if (daytotal > 0)
			printf("There are %d days!", daytotal);
		else
			puts("NO!");
		puts("Pleaase enter year,month and days:");
	}
	puts("Bye!");
	getchar();
	return 0;
}

int days(int day, int mon, int year)
{
	int total,i;
	if (leap(year))months[1].days = 29;
	else months[1].days = 28;
	if (mon < 1 || mon>12 || day<1 || day>months[mon - 1].days)return(-1);
	else
	{
		for (i = 0, total = 0;i < mon - 1;i++)
			total += months[i].days;
		return(total + day);
	}
}

int leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}