#include<stdio.h>
int main()
{
	void gg(int(*p)[3]);
	int s[3][3], i, j;
	for (i = 0;i < 3;i++)
		for (j = 0;j < 3;j++)
			scanf("%d", &s[i][j]);
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
			printf("%5d", s[i][j]);
			printf("\n");
	}
	printf("\n");
	printf("\n");
	gg(s);
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
			printf("%5d", s[i][j]);
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}
void gg(int (*p)[3])
{
	int i, j, t;
	for(i=0;i<3;i++)
		for (j = i;j < 3;j++)
		{
			t = *(*(p + i) + j);
			*(*(p + i) + j) = *(*(p + j) + i);
			*(*(p + j) + i) = t;
		}
}