/*����ַ������ʡ���������*/
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define stop '|'
int main(void)
{
	char c;
	char prev;     //��һ�������ַ�
	long n_chars = 0;     //�ַ���
	int n_lines = 0;      //����
	int n_words = 0;      //������
	int p_lines = 0;      //�������еĸ���
	bool inword = false;  //���c��һ�������У�inword=true;
	printf("�����룺\n");
	prev = '\n';
	while ((c = getchar()) != stop)
	{
		n_chars++;      //ͳ���ַ���
		if (c == '\n')  
			n_lines++;  //ͳ������
		if (!isspace(c) && !inword)
		{
			inword = true;   //��ʼһ���µ���
			n_words++;      //ͳ�Ƶ�����Ŀ
		}
		if (isspace(c) && inword)
			inword = false;  //���ﵥ�ʵ�ĩβ
		prev = c;   //�����ַ�
	}
	if (prev != '\n')p_lines = 1;//�����Ч�е���Ŀ
	printf("cahrters=%ld,word=%d,lines=%d,", n_chars, n_words, n_lines);
	printf("partial lines =%d", p_lines);
	getchar();
	getchar();
	return 0;
}