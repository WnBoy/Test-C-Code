#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	int i = 0;
	char str[3][10];
	if ((fp = fopen("I:\\CCstring.dat", "r")) == NULL)
	{
		printf("打开文件失败");
		exit(0);
	}
	while (fgets(str[i], 10, fp) != NULL)
	{
		printf("%s", str[i]);
		i++;
	}
	fclose(fp);
	return 0;
}