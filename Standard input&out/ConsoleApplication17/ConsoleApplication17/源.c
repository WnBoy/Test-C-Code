#include<stdio.h>
int main()
{
	char s[81];
	int i, num = 0, word = 0;
	gets(s);
	for (i = 0; s[i] != '\0';i++)
	{
		if (s[i] == ' ')
			word = 0;
		else if (word == 0)
		{
			word = 1;
			num++;
		}
		
	}
	printf("%d\n", num);
	getchar();
	return 0;
}