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
		printf("���������ݣ�\n");
		scanf("%ld,%ld,%d,%ld", &tax_list[i].left, &tax_list[i].right, &tax_list[i].tax, &tax_list[i].deduct);
	}
}
int main()
{
	FILE*fp;
	TAX_LIST tax_list[SIZE];
	if ((fp = fopen("E:\\TAX.din", "wb")) == NULL)
	{
		printf("���ļ�ʧ��");
		exit(1);
	}
	acceptance(tax_list);
	if ((fwrite(tax_list, sizeof(TAX_LIST), SIZE, fp)) != SIZE)
		printf("�ļ�����\n");
	fclose(fp);
	return 0;
}