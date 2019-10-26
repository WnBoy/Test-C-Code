#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	int i, str[5];
	if ((fp = fopen("E:\\YYY.txt", "rb")) == NULL)
		printf("打开111111文件失败");
	for (i = 0;i < 5;i++)
	{
		if (fread(&str[i], sizeof(int), 1, fp) != 1)
			printf("打开文件失败");
	}
	for (i = 0;i < 5;i++)
		printf("%5d", str[i]);
	fclose(fp);
	getchar();
	return 0;
}