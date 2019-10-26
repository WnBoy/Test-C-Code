#include<stdio.h>
int main()
{
	void gg(int **s, int n);
	int i,n, str[20], **p, *pstr[20];
	printf("please enter n:");
	scanf("%d", &n);
	for (i = 0;i < n;i++)
		pstr[i] = &str[i];
	printf("please enter these number:");
	for (i = 0;i < n;i++)
		scanf("%d", pstr[i]);
	p = pstr;
	gg(p,n);
	printf("Now,the sequence is:");
	for(i=0;i<n;i++)
	printf("%3d", *pstr[i]);
	printf("\n");
	getchar();
	getchar();
	return 0;
}
void gg(int **s,int n)
{
	int i, j, *t;
	for(i=0;i<n-1;i++)
		for (j = i + 1;j < n;j++)
			if(**(s+i)>**(s+j))
		{
				t = *(s + i);
				*(s + i) = *(s + j);
				*(s + j) = t;
		}
}