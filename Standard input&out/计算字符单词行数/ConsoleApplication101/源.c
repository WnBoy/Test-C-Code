/*检查字符、单词、行数多少*/
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define stop '|'
int main(void)
{
	char c;
	char prev;     //上一个输入字符
	long n_chars = 0;     //字符数
	int n_lines = 0;      //行数
	int n_words = 0;      //单词数
	int p_lines = 0;      //不完整行的个数
	bool inword = false;  //如果c在一个单词中，inword=true;
	printf("请输入：\n");
	prev = '\n';
	while ((c = getchar()) != stop)
	{
		n_chars++;      //统计字符数
		if (c == '\n')  
			n_lines++;  //统计行数
		if (!isspace(c) && !inword)
		{
			inword = true;   //开始一个新单词
			n_words++;      //统计单词数目
		}
		if (isspace(c) && inword)
			inword = false;  //到达单词的末尾
		prev = c;   //保存字符
	}
	if (prev != '\n')p_lines = 1;//检测无效行的数目
	printf("cahrters=%ld,word=%d,lines=%d,", n_chars, n_words, n_lines);
	printf("partial lines =%d", p_lines);
	getchar();
	getchar();
	return 0;
}