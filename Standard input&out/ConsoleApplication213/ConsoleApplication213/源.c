#include<stdio.h>
void del(char*s);
int main(void)
{
	char str[50];
	puts("Please enter strings:");
	gets(str);
	while (*str!='q')
	{
		del(str);
		puts(str);
		puts("Please continue enter strings:");
		gets(str);
	}
	puts("Quit!");
	getchar();
	return 0;
}

void del(char*s)
{
	char *t;
	while (*s != '\0')
	{
		if (*s == ' ')
		{
			t = s;
			while (*t != '\0')
			{
				*t = *(t+1);
				t++;
			}
			s--;
		}
			s++;
	}
}