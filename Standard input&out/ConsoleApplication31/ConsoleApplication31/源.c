#include<stdio.h>
#include<string.h>
int main()
{
	void gg(char s[], int k);
	int n;
	char s[10];
	gets(s);
	n = strlen(s);
	gg(s,n);
	printf("%s\n", s);
	getchar();
	return 0;

}
void gg(char s[], int k)
{
	int i;
	char t;
	for(i=0;i<k/2;i++,k--)
		{
		t = s[i];
		s[i] = s[k];
		s[k] = t;
}
}
