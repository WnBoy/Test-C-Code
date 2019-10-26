/*判断一个数是不是素数*/
#include<stdio.h>
#include<stdbool.h>  //布朗类型数据的头文件
int main(void)
{
	unsigned long num;
	unsigned long div;
	bool isprime;    //布朗类型数据
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
				isprime = false;//不是素数将标志位转换
			}
		}
		if (isprime)printf("%lu is prime.\n",num);//
		printf("please enter another integer for analysis;");
		printf("enter q to quit.\n");
	}
	printf("Bye.\n");//当输入为q时，则会输出Bye
	return 0;
}