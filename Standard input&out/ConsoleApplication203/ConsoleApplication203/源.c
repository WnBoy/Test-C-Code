#include<stdio.h>
#include<ctype.h>
void input(char str[],int n);
int main(void)
{
	char s[20];
	int k;
	puts("please enter k:");
	scanf("%d", &k);
	printf("Please input strings:");
	input(s, k);
	puts(s);
	getchar();
	getchar();
	return 0;
}

void input(char str[], int n)
{
	int i=0;
	while ( getchar() != '\n')
		continue;
	while (i < n)
	{
		str[i++] = getchar();
		if (isspace(str[i]))break;
	}
	str[i] = '\0';
}