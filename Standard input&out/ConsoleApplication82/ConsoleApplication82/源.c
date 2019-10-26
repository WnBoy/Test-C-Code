#include<stdio.h>
#include<stdlib.h>
#define SIZE 9
typedef struct tax_st
{
	long left;
	long right;
	int tax;
	long deduct;
}TAX_LIST;
void acceptance(TAX_LIST tax_list[])
{
	int i;
	for (i = 0;i < SIZE;i++)
	{
		printf("请输入数据：\n");
		scanf("%ld,%ld,%d,%ld", &tax_list[i].left, &tax_list[i].right, &tax_list[i].tax, &tax_list[i].deduct);
	}
}
int main()
{
	FILE*fp;
	TAX_LIST tax_list[SIZE];
	if ((fp = fopen("E:\\TAX.din", "wb")) == NULL)
	{
		printf("打开文件失败");
		exit(1);
	}
	acceptance(tax_list);
	if ((fwrite(tax_list, sizeof(TAX_LIST), SIZE, fp)) != SIZE)
		printf("文件错误\n");
	fclose(fp);
	return 0;
}