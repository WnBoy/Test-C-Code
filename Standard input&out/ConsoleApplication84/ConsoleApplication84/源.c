#include<stdio.h>
#include<stdlib.h>
void gg(int str[])
{
	int i;
	printf("���������ݣ�");
	for (i = 0;i < 5;i++)
		scanf("%d", &str[i]);
}
int main()
{
	FILE *fp;
	int str[5], i;
	if ((fp = fopen("E:\\YYY.txt", "wb")) == NULL)
	{
		printf("�ļ���ʧ��");
		exit(1);
	}
	gg(str);
	for (i = 0;i < 5;i++)
	{
		if ((fwrite(&str[i], sizeof(int), 1, fp)) != 1)
			printf("���ļ�ʧ��");
	}
	fclose(fp);
	return 0;
}