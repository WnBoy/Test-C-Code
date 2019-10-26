#include<stdio.h>
#include<stdlib.h>
void file_read(struct seat*pt, char*str);
void show_one(struct seat*pt);
void show_two(struct seat*pt);
void dalate(struct seat*pt);
void show_three(struct seat*pt);
void assign(struct seat*pt);
void write_file(struct seat*pt, char*str);
struct seat {
	int sea_non;
	int dis;
	char fir_name[10];
	char las_name[10];
};
struct seat seats[12] =
{
	{ 101,0 },
	{ 102,0 },
	{ 103,0 },
	{ 104,0 },
	{ 105,0 },
	{ 106,0 },
	{ 107,0 },
	{ 108,0 },
	{ 109,0 },
	{ 110,0 },
	{ 111,0 },
	{ 112,0 }
};
int main(void)
{
	char ch[10];
	file_read(seats, "seats.dat");
	puts("To choose a function,enter its letter label:");
	puts("a)Show number of empty seats");
	puts("b)Show list of empty seats");
	puts("c)Show alphabetical list of seats");
	puts("d)Assign a customer to a seat assignment");
	puts("e)Delete a seat assignment");
	puts("f)Quit!");
	while (gets(ch) != NULL)
	{
		switch (ch[0])
		{
		case 'a':show_one(seats);break;
		case 'b':show_two(seats);break;
		case 'c':show_three(seats);break;
		case 'd':assign(seats);break;
		case 'e':dalate(seats);break;
		default:write_file(seats, "seat.dat");puts("Quit!");exit(1);
		}
		puts("To choose a function,enter its letter label:");
		puts("a)Show number of empty seats");
		puts("b)Show list of empty seats");
		puts("c)Show alphabetical list of seats");
		puts("d)Assign a customer to a seat assignment");
		puts("e)Delete a seat assignment");
		puts("f)Quit!");
	}
	getchar();
	return 0;
}
void file_read(struct seat *pt, char*str)
{
	FILE*fp;
	while ((fp = fopen(str, "a+b")) == NULL)
	{
		fprintf(stderr, "Can't open file.\n");
		exit(1);
	}
	rewind(fp);
	while (fread(pt, sizeof(struct seat), 12, fp) == 1)
		continue;
	fclose(fp);
	printf("read is sucess!\n");
}

void show_one(struct seat*pt)
{
	int i;
	int total = 0;
	for (i = 0;i < 12;i++)
	{
		if (pt[i].dis)
			total++;
	}
	printf("Empty seats are %d seat.", total);
}

void show_two(struct seat*pt)
{
	int i;
	for (i = 0;i < 12;i++)
	{
		if (pt[i].dis)printf("empty:%d", pt[i].sea_non);
	}
}

void show_three(struct seat*pt)
{
	int i;
	puts("seat list:");
	for (i = 0;i < 12;i++)
	{
		if (pt[i].dis)
			printf("%s  %s", pt[i].fir_name, pt[i].las_name);
		else
			puts("empty!");
	}
}

void assign(struct seat*pt)
{
	int number, i;
	printf("Please enter number:");
	scanf("%d", &number);
	for (i = 0;i < 12;i++)
	{
		if (pt[i].sea_non == number)
		{
			if (pt[i].dis)printf("This seat is full.");
			else
			{
				puts("Please enter first name:");
				gets(pt[i].fir_name);
				puts("Please enter last name:");
				gets(pt[i].las_name);
				pt[i].dis = 1;
				puts("success assign!");
			}
		}
		else
			puts("you input is err");
	}
}

void dalate(struct seat*pt)
{
	int number, i;
	puts("Please input number:");
	scanf("%d", &number);
	for (i = 0;i < 12;i++)
	{
		if (pt[i].sea_non == number)
		{
			if (pt[i].dis == 0)
				printf("This seat is empty!");
			else
			{
				pt[i].dis = 0;
				puts("Delete success!");
			}
		}
	}
}

void write_file(struct seat*pt, char*str)
{
	FILE*fp;
	while ((fp = fopen(str, "wb")) == NULL)
	{
		puts("Open file is failure!");
		exit(1);
	}
	fwrite(pt, sizeof(struct seat), 12, fp);
	fclose(fp);
}