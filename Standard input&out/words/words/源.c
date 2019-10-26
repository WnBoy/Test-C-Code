#include <stdio.h>
#define IN 1
#define OUT 0
int main()
{
	int c, nc, nl, nw;
	nc = nl = nw = 0;
	int flag = OUT;
	while ((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			flag = OUT;
		else
		{
			++nw;
			flag = IN;
		}
	}
	printf("nl=%d\nnc=%d\nnw=%d\n", nl, nc, nw);
	getchar();
	return 0;
}