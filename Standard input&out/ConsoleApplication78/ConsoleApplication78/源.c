#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	char str[3][10], temp[10];
	int i, j, k, n = 3;
	printf("�������ַ�����\n");
	for (i = 0;i < n;i++)
		gets(str[i]);
	for (i = 0;i < n - 1;i++)
	{
		k = i;
		for (j = i + 1;j < n;j++)
			if (strcmp(str[k], str[k]) > 0)k = j;
		if (i != k) 
		{
			strcpy(temp, str[i]);
			strcpy(str[i], str[k]);
			strcpy(str[k], temp);
		}
	}
	if ((fp = fopen("I:\\CC\\string.dat", "w")) == NULL)
	{
		printf("���ļ�ʧ��");
		exit(0);
	}
	printf("\nThe new sequence:\n");
	for (i = 0;i < n;i++)
	{
		fputs(str[i], fp);
		fputs('\n', fp);
		printf("%s", str[i]);
	}
	fclose(fp);
	getchar();
	return 0;
}