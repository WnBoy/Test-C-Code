#include<stdio.h>
#include"process.h"
#define SIZE 9
typedef struct tax_st
{
	long left;
	long right;
	int tax;
	long deduct;
}TAX_LIST;
void acceptdate(TAX_LIST tax_list[])
{
	int i;
	for (i = 0;i < SIZE;i++)
	{
		printf("Please enter date:");
		scanf("%d", &tax_list[i].left);
		scanf("%d", &tax_list[i].right);
		scanf("%d", &tax_list[i].tax);
		scanf("%d", &tax_list[i].deduct);
	}
}
int main()
{
	FILE *fp;
	TAX_LIST tax_list[SIZE];
	if((fp = fopen("d:\\TAX.din", "wb")) == NULL)
	{
		printf("\ncannot open file\n");
		exit(1);
	}
	acceptdate(tax_list);
	if (fwrite(tax_list, sizeof(TAX_LIST), SIZE, fp) != SIZE)
		printf("file write error\n");
	fclose(fp);
	return 0;
}