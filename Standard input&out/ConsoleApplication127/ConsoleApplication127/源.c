#include<stdio.h>
int main(void)
{
	int i;
	for (i = 0;getchar() != EOF;i++);
	printf("sum=%d", i);
	/*char ch;
	int sum=0;
	while ((ch = getchar()) != EOF)
	{
		sum++;
	}
	printf("sum=%d", sum);*/
	getchar();
	return 0;
}
