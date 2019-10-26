#include<stdio.h>
int main()
{
	void fund(int *p, int m);
	int i, s[10],m;
	printf("please input ten number:");
	for (i = 0;i < 10;i++)
		scanf("%d", &s[i]);
	printf("\n");
	printf("please input m:");
		scanf("%d", &m);
	fund(s,m);
	for (i = 0;i < 10;i++)
		printf("%3d", s[i]);
	getchar();
	getchar();
	return 0;
}
void fund(int *p,int m)
{
	int r[10], i,j;
	for (i = 0;i < 10 - m;i++)
		r[i] = p[i];
	for (i = 0;i < m;i++)
		p[i] = p[10 - m + i];
	for (i = m, j = 0;i < 10;j++, i++)
		p[i] = r[j];
}