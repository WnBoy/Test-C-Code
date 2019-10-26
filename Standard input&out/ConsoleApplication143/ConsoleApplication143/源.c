#include<stdio.h>
#include<stdio.h>
#define SIZE 81
#define LIM 20
#define HALT " "
void stsrt(char *strings[], int num);
int main(void)
{
	char input[LIM][SIZE];
	char *ptstr[LIM];
	int ct = 0;
	int k;
	printf("Input up to %d lines,and I will sort them.\n",LIM);
	printf("To stop,press the Enter key at a line's start.\n");
	while (ct < LIM&&gets(input[ct]) != NULL&&*input[ct] != '\0')
	{
		ptstr[ct] = input[ct];
		ct++;
	}
	stsrt(ptstr, ct);
	for (k = 0;k < ct;k++)
		puts(ptstr[k]);
	getchar();
	return 0;
}
void stsrt(char *strings[], int num)
{
	char *t;
	int i, j;
	for(i=0;i<num-1;i++)
		for (j = i + 1;j < num;j++)
			if (strcmp(strings[i], strings[j]) > 0)
			{
				t = strings[i];
				strings[i] = strings[j];
				strings[j] = t;
		}
}