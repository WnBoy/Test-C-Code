#include<stdio.h>
int main(void)
{
	float n_avege, m_avege;
	int n, m, x;
	n = m = 0;
	int n_sum, m_sum;
	n_sum = m_sum = 0;
	printf("please enter number:\n");
	scanf("%d", &x);
	while (x != 0)
	{
		if (x % 2 == 0)
		{
			n++;
			n_sum+=x;
		}

		else
		{
			m++;
			m_sum += x;\
		}
		scanf("%d", &x);
	}
	n_avege = n_sum / n;
	m_avege = m_sum / m;
	printf("偶数个数：%d  平均值：%f", n, n_avege);
	printf("奇数个数：%d  平均值：%f", m, m_avege);
	getchar();
	getchar();
	return 0;
}