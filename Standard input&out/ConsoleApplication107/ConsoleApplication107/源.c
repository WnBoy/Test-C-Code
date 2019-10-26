#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char ch;
	int n_blank=0,n_huan=0,n_other=0;
	while ((ch = getchar()) != '#')
	{
		if (isblank(ch))n_blank++;
		else
		{
			if (ch == '\n')n_huan++;
			else n_other++;
		}
	}
	printf("n_blank=%d\nn_huan=%d\nn_other=%d", n_blank, n_huan, n_other);
	getchar();
	getchar();
	return 0;
}