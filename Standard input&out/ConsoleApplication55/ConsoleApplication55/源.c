#include<stdio.h>
int main()
{
	void gg(int(*p)[5]);
	int s[5][5], i, j;
	for (i = 0;i < 5;i++)
		for (j = 0;j < 5;j++)
			scanf("%d", &s[i][j]);
	printf("\n");
	for (i = 0;i < 5;i++)
	{
		for (j = 0;j < 5;j++)
			printf("%3d", s[i][j]);
		printf("\n");
	}
	printf("\n");
	gg(s);
	for (i = 0;i < 5;i++)
	{
		for (j = 0;j < 5;j++)
			printf("%3d", s[i][j]);
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}
void gg(int(*p)[5])
{
	int i, j, t;
	int *min, *max;
	min = max = *p;
	for (i = 0;i < 5;i++)
		for (j = 0;j < 5;j++)
			if (*(*(p + i) + j) > *max)
				max = *(p + i) + j;
	t = *(*(p + 2) + 2);
	*(*(p + 2) + 2) = *max;
	*max = t;
	for (i = 0;i < 5;i++)
		for (j = 0;j < 5;j++)
			if (*(*(p + i) + j) < *min)
				min = *(p + i) + j;
	t = **p;
	**p = *min;
	*min = t;
	for (i = 0;i < 5;i++)
		for (j = 0;j < 5;j++)
			if(*(*(p + i) + j)>**p&&*(*(p + i) + j)<*min)
				min = *(p + i) + j;
	t = *(*p + 4);
	*(*p + 4) = *min;
	*min = t;
	for (i = 0;i < 5;i++)
		for (j = 0;j < 5;j++)
			if(*(*(p + i) + j)>*(*p + 4)&& *(*(p + i) + j)<*min)
				min = *(p + i) + j;
	t = **(p + 4);
	**(p + 4) = *min;
	*min = t;
	for (i = 0;i < 5;i++)
		for (j = 0;j < 5;j++)
			if (*(*(p + i) + j) > **(p + 4) && *(*(p + i) + j) < *min)
				min = *(p + i) + j;
	t = *(*(p + 4) + 4);
	*(*(p + 4) + 4) = *min;
	*min = t;
}