#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE*fp;
	char ch, filename[10];
	printf("�������ļ�����");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("�޷�����\n");
		exit(0);
	}
	ch = getchar();
	printf("������һ��׼���浽�����е��ַ�������#��������");
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