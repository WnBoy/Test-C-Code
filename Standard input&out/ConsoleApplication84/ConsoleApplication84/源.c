#include<stdio.h>
#include<stdlib.h>
void gg(int str[])
{
	int i;
	printf("请输入数据：");
	for (i = 0;i < 5;i++)
		scanf("%d", &str[i]);
}
int main()
{
	FILE *fp;
	int str[5], i;
	if ((fp = fopen("E:\\YYY.txt", "wb")) == NULL)
	{
		printf("文件打开失败");
		exit(1);
	}
	gg(str);
	for (i = 0;i < 5;i++)
	{
		if ((fwrite(&str[i], sizeof(int), 1, fp)) != 1)
			printf("打开文件失败");
	}
	fclose(fp);
	return 0;
}