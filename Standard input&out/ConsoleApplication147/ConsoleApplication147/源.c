#include<stdio.h>
int is_within(char ch, char*strs);
int main(viod)
{
	char c;
	char a[50];
	char *str;
	str = a;
	printf("please enter a char and string:\n");
	c = getchar();
	getchar();
	gets(str);
	if(is_within(c, str))printf("YES!!!");
	else printf("NO!!!");
	getchar();
	return 0;
}
int is_within(char ch, char*strs)
{
	int dd=0;
	for (;*strs != '\0';strs++)
		if (*strs == ch) {
			dd = 1;break;
		}
		return dd;
}