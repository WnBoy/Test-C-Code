#include<stdio.h>
int main(void)
{
	int x,n=0, m=0, n_sum=0, m_sum=0;
	printf("please enter number:\n");
	scanf("%d", &x);
	while (1)
	{
		if (x == 0)break;
		switch (x % 2)
		{
		case 0:n++;n_sum += x;break;
		case 1:m++;m_sum += x;break;
		}
		scanf("%d", &x);
	}
	printf("ż��������%d  ƽ������%d\n", n, n_sum / n);
	printf("����������%d  ƽ������%d\n", m, m_sum / n);
	getchar();
	getchar();
	return 0;
}