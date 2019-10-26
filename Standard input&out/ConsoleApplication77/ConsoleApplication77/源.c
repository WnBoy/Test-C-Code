#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE*in, *out;
	char ch, infile[10], outfile[10];
	printf("请输入读文件的文件名：");
	scanf("%s", infile);
	printf("请输入写文件的文件名：");
	scanf("%s", outfile);
	if ((in = fopen(infile, "r")) == NULL)
	{
		printf("无法打开文件");
		exit(0);
	}
	if ((out = fopen(outfile, "w")) == NULL)
	{
		printf("无法打开文件");
		exit(0);
	}
	while (!feof(in))
	{
		ch = fgetc(in);
		fputc(ch, out);
		putchar(ch);
	}
	putchar('\n');
	fclose(in);
	fclose(out);
	return 0;
}