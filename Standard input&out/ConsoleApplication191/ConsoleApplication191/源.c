#include<stdio.h>
long fact(int n);
long rfact(int n);
int main(void)
{
	int num;
	printf("请输入一个数：");
	while (scanf("%d", &num) == 1)
	{
		if (num < 0)printf("输入的数据太小.\n");
		else
		{
			if (num > 12)printf("数据太大.\n");
			else 
			{
				printf("for循环的结果：%d\n", fact(num));
				printf("递归的结果：%ld\n", rfact(num));
			}
		}
		printf("请输入一个数：");
	}
	puts("Bye!");
	return 0;
}

long fact(int n)
{
	int ant = 1;
	for (;n > 1;n--)
		ant *= n;
	return ant;
}

long rfact(int n)
{
	int ant;
	if (n > 0)ant = n*rfact(n - 1);
	else ant = 1;
	return ant;
}