/******************
��һʮ���Ʊ�ɶ�����
******************/
#include<stdio.h>
void gg(unsigned int n);
int main(void)
{
	unsigned long num;
	printf("������һ�����֣�");
	while (scanf("%ul", &num) == 1)
	{
		gg(num);
		putchar('\n');
		printf("������һ�����֣�");
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