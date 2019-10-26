#include<stdio.h>
int main()
{
	void copy(char *p1, char *p2, int m);
	int m;
	char s1[20], s2[20];
	printf("Please enter a string:");
	gets(s1);
	printf("Please into m:");
	scanf("%d", &m);
	copy(s1, s2, m);
	printf("%s\n", s2);
	getchar();
	getchar();
	return 0;
}
void copy(char *p1, char *p2, int m)
{
	char *t;
	t = p1 + m - 1;
	for (;*t!= '\0';t++,p2++)
		*p2 = *t;
	*p2 = '\0';
}