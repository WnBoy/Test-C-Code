#include<stdio.h>
#include<string.h>
#define CSIZE 4
void average(struct student* pt);
void s_print(struct student*pt);
struct name {
	char first[10];
	char last[10];
};

struct student {
	struct name names;
	float grade[3];
	float ave;
};

int main(void)
{
	int i,k;
	char in_fname[10];
	char in_lname[10];
	struct student students[CSIZE] =
	{
		{"sjjal","asjlda",0,0,0,0},
		{"asdas","sadla",0,0,0,0},
		{"sadak","sahkda",0,0,0,0},
		{"sjjda","sada",0,0,0,0}
	};
	puts("PLease enter name:");
	while (gets(in_fname) != NULL&&in_fname[0] != '\0'&&gets(in_lname)!=NULL&&in_lname[0]!='\0')
	{
		for (i = 0;i < CSIZE;i++)
			if ((strcmp(students[i].names.first, in_fname) == 0)&&
				(strcmp(students[i].names.last,in_lname)==0))
			{
				puts("Please enter grade:");
				for(k=0;k<3;k++)
				scanf("%f", &students[i].grade[k]);
				break;
			}
			else puts("name is roung!");
		puts("PLease enter name:");
	}
	average(students);
	s_print(students);

	getchar();
	return 0;
}

void average(struct student* pt)
{
	int i, k;
	float total=0;
	for (k = 0;k < CSIZE;i++)
	{
		for (i = 0;i < 3;i++)
			total += pt[k].grade[i];
		pt[k].ave = total/3;
	}
}

void s_print(struct student*pt)
{
	int n, m;
	for (n = 0;n < CSIZE;n++)
	{
		printf("%s %s grade is", pt[n].names.first, pt[n].names.last);
		for (m = 0;m < 3;m++)
			printf(" %d ", pt[n].grade[m]);
		printf(",ave is %f", pt[m].ave);
	}
}