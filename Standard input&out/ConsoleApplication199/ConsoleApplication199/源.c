#include<stdio.h>
void sum(int *p, int*p1, int*p2);
int main(void)
{
	int i;
	int s1[3] = { 1,2,3 };
	int s2[3] = { 4,5,6 };
	int s[3];
	sum(s, s1, s2);
	for (i = 0;i < 3;i++)
		printf("%5d", s[i]);
	getchar();
	return 0;
}

void sum(int *p, int*p1, int*p2)
{
	int j;
	for (j = 0;j < 3;j++)
		*p++ = (*p1++) + (*p2++);
	return;
}