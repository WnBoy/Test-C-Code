#include<stdio.h>
int main()
{
	char i, j, k;
	for (i = 'x';i <= 'z'; i++)
		for (j = 'x';j <= 'z';j++)
			if (i != j)
				for (k = 'x';k <= 'z';k++)
					if (k != i&&k != j)
						if (i != 'x'&&k != 'x'&&k != 'z')
							printf("A--%c\nB--%c\nC--%c\n", i, j, k);
	getchar();
	return 0;

}