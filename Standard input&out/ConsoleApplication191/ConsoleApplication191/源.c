#include<stdio.h>
long fact(int n);
long rfact(int n);
int main(void)
{
	int num;
	printf("������һ������");
	while (scanf("%d", &num) == 1)
	{
		if (num < 0)printf("���������̫С.\n");
		else
		{
			if (num > 12)printf("����̫��.\n");
			else 
			{
				printf("forѭ���Ľ����%d\n", fact(num));
				printf("�ݹ�Ľ����%ld\n", rfact(num));
			}
		}
		printf("������һ������");
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