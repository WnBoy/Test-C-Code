/******************
把一十进制变成二进制
******************/
#include<stdio.h>
void gg(unsigned int n);
int main(void)
{
	unsigned long num;
	printf("请输入一个数字：");
	while (scanf("%ul", &num) == 1)
	{
		gg(num);
		putchar('\n');
		printf("请输入一个数字：");
	}
	printf("Done.");
	getchar();
	return 0;
}
void gg(unsigned int n)
{
	int r;
	r = n % 2;
	if (n >= 2)gg(n/2);
	putchar('0'+r);
	return;
}