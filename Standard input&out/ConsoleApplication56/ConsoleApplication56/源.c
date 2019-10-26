#include<stdio.h>
#include<string.h>
int main()
{
	void sort(char*s[]);
	int i;
	char *p[10], str[10][20];
	for (i = 0;i < 10;i++)
		p[i] = str[i];
	printf("please enter 10 strinf:\n");
	for (i = 0;i < 10;i++)
		scanf("%s", p[i]);
	sort(p);
	printf("Now,the sequence is:\n");
	for (i = 0;i < 10;i++)
		printf("%s\n", p[i]);
	getchar();
	return 0;
}
void sort(char*s[])
{
	int i, j, k;
	char *t;
	for (i = 0;i < 9;i++)
	{
		k = i;
		for (j = i + 1;j < 10;j++)
			if (strcmp(*(s + j), *(s + k)) > 0)
				k = j;
		if (k != i)
		{
			t = *(s + i);
			*(s + i) = *(s + k);
			*(s + k) = *t;
		}
	}

}