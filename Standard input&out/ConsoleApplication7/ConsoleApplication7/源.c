#include<stdio.h>
int main()
{
	int i;
	float sum = 0, num, ave;
	for (i = 1;i <= 1000;i++)
	{
		printf("please input num:");
		scanf("%f", &num);
		sum = sum + num;
		if (sum >= 100000)break;
	}
	ave = sum / i;
	printf("%d\n%f\n", i, ave);
	getchar();
	return 0;
}