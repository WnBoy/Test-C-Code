#include<stdio.h>
int main()
{
	int gy(int x, int y);
	int gb(int z, int c);
	int n, m;
	printf("Please input two number:");
	scanf("%d%d", &n, &m);
	printf("gy is %d\ngb is %d\n", gy(n, m), gb(n, m));
	getchar();
	getchar();
	return 0;

}
int gy(int x, int y)
{
	int k;
	k = (x < y) ? x : y;
	for (;k >= 1;k--)
		if ((x%k == 0) && (y%k == 0))
			break;
	return(k);
}
int gb(int z, int c)
{
	int j;
	j = (z > c) ? z : c;
	for (;;j++)
		if ((j%z == 0) && (j%c == 0))
			break;
	return(j);

}