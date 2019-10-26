#include<stdio.h>
#include<string.h>
void put1(char*p[10], int n);
void put2(char*p[10],int n);
void put3(char*p[10],int n);
void put4(char*p[10],int n);
int first_word_len(char*strings);
int main(void)
{
	char x;
	int n = 0;
	char str[10][50];
	char*ptr[50];
	puts("please enter strs:");
	while (n<10&&gets(str[n])!=NULL&&str[n][0]!='\0')
	{
		ptr[n] = str[n];
		n++;
	}
	puts("please enter x:");
	while (x = getchar() != 'q')
	{
		puts("输入x为1则输出初始字符列表；");
		puts("输入x为2则按ASCII顺序输出字符串；");
		puts("输入x为3则按长度递增顺序输出字符串；");
		puts("输入x为4则按字符串中的第一个单词长度输出字符串；");
		puts("输入x为q则退出！");
		switch (x)
		{
		case 1:put1(ptr,n);break;
		case 2:put2(ptr,n);break;
		case 3:put3(ptr,n);break;
		case 4:put4(ptr,n);break;
		default:break;
		}
	}
	puts("Quit!");
	getchar();
	return 0;
}

void put1(char*p[10],int n)
{
	int i=0;
	while (i < n)
	{
		puts(p[i]);
		i++;
	}
}

void put2(char*p[10],int n)
{
	char*t;
	char*str[10];
	int i, j=0;
	int k=0;
	int m = 0;
	while (k < n)
	{
		str[k] = p[k];
		k++;
	}
	for (i = 0;j < n-1;i++)
		for (j = i;j < n;j++)
			if (strcmp(p[i], str[j]) > 0)
			{
				t = str[i];
				str[i] = str[j];
				str[j] = t;
			}
	while (m < n)
		puts(str[m++]);
}

void put3(char*p[10],int n)
{
	char*str[10];
	char *t;
	int i=0;
	int d,m;
	int k=0;
	while (i < n)
	{
		str[i] = p[i];
		i++;
	}	
	for (d = 0;d < n-1;d++)
		for(m=d+1;m<n;m++)
			if (strlen(str[d]) > strlen(str[m]))
			{
				t = str[d];
				str[d] = str[m];
				str[m] = t;
			}
	while (k < n)
		puts(str[k++]);
}

void put4(char*p[10],int n)
{
	char*str[10];
	char*t;
	int i,j;
	int k=0;
	int d=0;
	while (k < n)
	{
		str[k] = p[k];
		k++;
	}
	for(i=0;i<n-1;i++)
		for(j=i;j<n;j++)
			if (first_word_len(str[i]) > first_word_len(str[j]))
			{
				t = str[i];
				str[i] = str[j];
				str[j] = t;
            }
	while (d < n)
		puts(str[n]);
}

int first_word_len(char*strings)
{
	int n=0;
	while (*(strings + n) != ' ')
		n++;
	return n;
}