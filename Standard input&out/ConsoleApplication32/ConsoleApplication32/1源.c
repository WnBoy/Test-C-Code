#include<stdio.h>
#include<string.h>
int main()
{
	void gg(char s[]);
	char s[10];
	scanf("%s", s);
	gg(s);
	printf("%s\n", s);
	getchar();
	return 0;

}
void gg(char s[])
{
	int i, k;
	char t;
	k = strlen(s);
	for (i = 0;i<k / 2;i++, k--)
	{
		t = s[i];
		s[i] = s[k - 1];
		s[k - 1] = t;
	}
}
