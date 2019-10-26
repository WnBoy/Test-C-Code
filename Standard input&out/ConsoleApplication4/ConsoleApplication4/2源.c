#include<stdio.h>
int main()
{
	int i;
	float ave, num, sum = 0;
	for (i = 1;i <= 1000;i++)
	{
		printf("please input num:");
		scanf("%f", &num);
		sum = sum + num;
		if (sum >= 100000)
			break;
	 }
	ave = sum / i;
	printf("sum=%d\nave=%f\n", i, ave);
	getchar();
	return 0;
}