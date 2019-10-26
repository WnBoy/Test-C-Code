#include<stdio.h>
void put1(char*p[10]);
int main(void)
{
	int i = 0;
	char str[10][50];
	char*ptr[10];

	while (i<10 && gets(str[i]) != NULL&&str[i][0] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	put1(ptr);
	getchar();
	return 0;
}

void put1(char*p[10])
{
	int i;
	while (i < 10)
	{
		puts(p[i]);
		i++;
	}
}