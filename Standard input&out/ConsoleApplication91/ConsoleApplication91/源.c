#include<stdio.h>
int main()
{
	int s[8] = { 4,9,3,7,7,1,4,2 };
	int cont[10];
	int i, j;
	for (i = 0;i < 10;i++)
		cont[i] = 0;
	for (i = 0;i < 8;i++)
		cont[s[i]] += 1;
	for(i=0;i<10;i++)
		if (cont[i] > 0)
		{
			for (j = 1;j <= cont[i];j++)
				printf("%5d", i);
		}
	getchar();
	return 0;
}