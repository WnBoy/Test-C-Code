#include<stdio.h>
int main()
{
	int i, j, t;
	int s[10];
	printf("please enter ten number:\n");
	for (i = 0;i < 10;i++)
		scanf("%d", s[i]);
	printf("\n");
	for(i=0;i<9;i++)
		for (j = 0;j < 9 - i;j++)
		{
			if (s[i] > s[i + 1])
			{
				t = s[i];
				s[i] = s[i+1];
				s[i+1] = t;
			}
		}
	for (i = 1;i < 10;i++)
		printf("%d", s[i]);
	printf("\n");
	getchar();
	return 0;
}