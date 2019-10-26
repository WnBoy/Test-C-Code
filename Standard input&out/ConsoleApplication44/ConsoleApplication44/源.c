#include<stdio.h>
int main()
{
	void mua(char from[], char to[]);
	char s1[] = { "I am a teacher." };
	char s2[] = { "You are a student." };
	printf("s1=%s\ns2=%s\n",s1,s2);
	printf("copy is:\n");
	mua(s1, s2);
	printf("s1=%s\ns2=%s\n", s1, s2);
	getchar();
	return 0;
}
void mua(char from[], char to[])
{
	int i, j;
	for (i = 0;from[i] != '\0';i++)
		to[i] = from[i];
	to[i] = '\0';
}