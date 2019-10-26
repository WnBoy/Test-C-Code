#include<stdio.h>
void put1(char*p[10],int m);
int main(void)
{
	int n = 0;
	char str[10][50];
	char*ptr[10];

	while (n<10 && gets(str[n]) != NULL&&str[n][0] != '\0')
	{
		ptr[n] = str[n];
		n++;
	}
	put1(ptr,n);
	getchar();
	return 0;
}

void put1(char*p[10],int m)
{
	int i=0;
	while (i < m)
	{
		puts(p[i]);
		i++;
	}
}
