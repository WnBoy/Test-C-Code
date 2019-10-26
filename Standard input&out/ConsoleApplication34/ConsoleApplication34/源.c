#include<stdio.h>
#include<string.h>
int main()
{
	void hh(char s1[20], char s2[20]);
	char c1[20], c2[20];
	scanf("%s%s", c1, c2);
	hh(c1, c2);
	printf("%s", c1);
	getchar();
	getchar();
	return 0;
}
void hh(char s1[20], char s2[20])
{
	int i, j;
	i = strlen(s1);
	for (j = 0;s2[j] != '\0';i++, j++)
		s1[i] = s2[j];
	s1[i] = '\0';

}