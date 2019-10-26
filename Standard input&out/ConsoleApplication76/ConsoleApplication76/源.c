#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE*fp;
	char ch, filename[10];
	printf("请输入文件名：");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("无法打开文\n");
		exit(0);
	}
	ch = getchar();
	printf("请输入一个准备存到磁盘中的字符串（以#结束）：");
	ch = getchar();
	while (ch != '#')
	{
		fputc(ch, fp);
		putchar(ch);
		ch = getchar();
	}
	fclose(fp);
	putchar('\n');
	getchar();
	return 0;
}