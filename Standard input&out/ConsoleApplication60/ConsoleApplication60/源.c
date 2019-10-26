#include<stdio.h>
#include<string.h>
int main()
{
	void gg(char **s);
	int i;
	char **p, *pstr[5], str[5][20];
	for (i = 0;i < 5;i++)
		pstr[i] = str[i];
	printf("please enter 5 strings:\n");
	for (i = 0;i < 5;i++)
		scanf("%s", pstr[i]);
	p = pstr;
	gg(p);
	printf("\nstring ok:\n");
	for (i = 0;i < 5;i++)
		printf("%s\n", pstr[i]);
	getchar();
	getchar();
	return 0;
}
void gg(char **s)
{
	char *t;
	int i, j;
	for(i=0;i<4;i++)
		for(j=i+1;j<5;j++)
			if (strcmp(*(s + i), *(s + j)) > 0)
			{
				t = *(s + i);
				*(s + i) = *(s + j);
				*(s + j) = t;
			}
}