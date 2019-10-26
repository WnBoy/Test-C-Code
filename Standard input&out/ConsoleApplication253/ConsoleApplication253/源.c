#include <stdio.h>
#define MAXLINE 1000
int getline(char str[], int n);
void copy(char str1[], char str2[]);
int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	max = 0;
	while (len=getline(line,MAXLINE)>0)
	{
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if(max>0)
	printf("%s", longest);
	getchar();
	return 0;
}

int getline(char str[], int n)
{
	int c, i;
	for (i = 0;i < n - 1 && (c = getchar()) != EOF&&c != '\n';++i)
		str[i] = c;
	if (c == '\n')
	{
		c = '\n';
		++i;
	}
	str[i] = '\0';
	return i;
}

void copy(char str1[], char str2[])
{
	int i;
	while (str1[i] = str2[i] != '\0')
		++i;
}