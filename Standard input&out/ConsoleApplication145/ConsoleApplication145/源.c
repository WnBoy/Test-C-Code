#include<stdio.h>
void gg(char *strs);
int main(void)
{
	char str[50];
	printf("please enter a strings:\n");
	gg(str);
	puts(str);
	getchar();
	return 0;
}
void gg(char *strs)
{
	scanf("%s", strs);
	return;
}