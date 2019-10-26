#include<stdio.h>
#include<stdlib.h>
#define SIZE 9
typedef struct tax_list
{
	long left;
	long right;
	int tax;
	long deduct;
}TAX_LIST;
void disp(TAX_LIST tax_list[])
{
	double salary, s, tax, ff;
	int i;
	printf("请输入税前扣除数：");
	scanf("%lf", &ff);
	printf("请输入工资：");
	scanf("%lf", &salary);
	if (salary >= 0)
	{
		s = salary - ff;
		if (s <= 0)
			tax = 0;
		else
		{
			for (i = 0;i < 8;i++)
			{
				if (s >= tax_list[i].left&&s < tax_list[i].right)
					tax = s*tax_list[i].tax / 100 - tax_list[i].deduct;
			}
			if (s >= tax_list[8].left)
				tax = s*tax_list[8].tax / 100 - tax_list[8].deduct;
		}
	}
	printf("应纳个人所得税额是%.2lf\n",tax);
}
int main()
{
	FILE *fp;
	TAX_LIST tax_list[SIZE];
	if ((fp = fopen("E:\\TAX.din", "rb")) == NULL)
	{
		printf("打开文件失败");
		exit(1);
	}
	if (fread(tax_list, sizeof(TAX_LIST), SIZE, fp) != SIZE)
	{
		printf("文件打开失败");
		exit(1);
	}
	disp(tax_list);
	fclose(fp);
	getchar();
	getchar();
	return 0;
}