/*�ж�һ�����ǲ�������*/
#include<stdio.h>
#include<stdbool.h>  //�����������ݵ�ͷ�ļ�
int main(void)
{
	unsigned long num;
	unsigned long div;
	bool isprime;    //������������
	printf("please enter an interger for analyis:");
	printf("Enter q to quit.\n");
	while (scanf("%lu", &num) == 1)
	{
		for (div = 2, isprime = true;(div*div) <= num;div++)
		{
			if (num%div == 0)
			{
				if (div*div != num)
					printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
				else
					printf("%lu is divisible by %lu.\n",num, div);
				isprime = false;//������������־λת��
			}
		}
		if (isprime)printf("%lu is prime.\n",num);//
		printf("please enter another integer for analysis;");
		printf("enter q to quit.\n");
	}
	printf("Bye.\n");//������Ϊqʱ��������Bye
	return 0;
}