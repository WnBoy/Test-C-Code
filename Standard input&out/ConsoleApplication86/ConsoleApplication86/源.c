#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	int i, str[5];
	if ((fp = fopen("E:\\YYY.txt", "rb")) == NULL)
		printf("��111111�ļ�ʧ��");
	for (i = 0;i < 5;i++)
	{
		if (fread(&str[i], sizeof(int), 1, fp) != 1)
			printf("���ļ�ʧ��");
	}
	for (i = 0;i < 5;i++)
		printf("%5d", str[i]);
	fclose(fp);
	getchar();
	return 0;
}