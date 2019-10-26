#include<stdio.h>
#include<string.h>
int main()
{
	char a[50],b[50];
	scanf("%s%s", a, b);
	int i, j;
	i = strlen(a);
	for (j = 0;b[j] != '\0';i++, j++)
		a[i] = b[j];
	a[i] = '\0';
	printf("%s\n", a);
	printf("\n");
	getchar();
	getchar();
	return 0;

}