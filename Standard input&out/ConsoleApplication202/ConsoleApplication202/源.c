#include<stdio.h>
#include<string.h>
#define SIZE 81
#define LIM 20
void stsrt(char*str[], int num);

int main(void)
{
	int ct = 0;
	int k;
	char input[LIM][SIZE];
	char*pstr[LIM];
	printf("请输入字符串\n");
	while (ct < LIM&&gets(input[ct])!= NULL&&input[ct][0] != '\0')
	{
		pstr[ct] = input[ct];
		ct++;
	}
	stsrt(pstr, ct);
	puts("\n这里是排序后的数据：");
	for (k = 0;k < ct;k++)
		puts(pstr[k]);
	getchar();
	return 0;
}

void stsrt(char*str[], int num)
{
	char*t;
	int i, j;
	for (i = 0;i < num-1;i++)
		for (j = i + 1;j < num;j++)
			if (strcmp(str[i], str[j]) > 0)
			{
				t = str[i];
				str[i] = str[j];
				str[j] = t;
		    }
}