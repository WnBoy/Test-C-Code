#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char ch;
	int n_k = 0;
	int n_h = 0;
	int n_others = 0;
	while ((ch = getchar()) != '#')
	{
		if (ch==' ')n_k++;
		else
		{
			if (ch == '\n')n_h++;
			else
				n_others++;
		}
	}
	printf("n_k=%d\tn_h=%d\tnothers=%d", n_k, n_h, n_others);
	getchar();
	getchar();
	return 0;
}