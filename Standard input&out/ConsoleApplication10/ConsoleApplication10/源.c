#include<stdio.h>
int main()
{
	int f1 = 1, f2 = 1, i;
	for (i = 1;i <= 20;i++)
	{
		printf("%15d%15d", f1, f2);
		f1 = f1 + f2;
		f2 = f1 + f2;
		if (i%2==0)
			printf("\n");
	}
	getchar();
	return 0;
	
}