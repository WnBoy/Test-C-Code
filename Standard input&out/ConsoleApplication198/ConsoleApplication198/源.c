#include<stdio.h>
int main(void)
{
	int d[5] = { 3,5,8,6,2 };
	printf("The max of d is %d", max(d));
	getchar();
	return 0;
}

int max(int*p)
{
	int z;
	z = *p;
	for (int j = 1;j < 5;j++)
	{
		if (*(p + j) > z)z = *(p + j);
	}
	return z;
}