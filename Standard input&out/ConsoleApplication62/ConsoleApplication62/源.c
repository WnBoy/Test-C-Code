#include<stdio.h>
int main()
{
	int w, n=0, i;
	char s[50];
	gets(s);
	w = 0;
	for (i = 0;s[i] != '\0';i++)
	{
		if (s[i]== ' ')w = 0;
		else if (w == 0)
		{
			n++;
			w = 1;
		}
	}
	printf("%d", n);
	getchar();
	return 0;
}