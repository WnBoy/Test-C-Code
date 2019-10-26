#include<stdio.h>
extern int rand1(void);
extern void srand1(unsigned int x);
int main(void)
{
	unsigned seed;
	int count;
	printf("please enter a seed:\n");
	while (scanf("%u", &seed) == 1)
	{
		srand1(seed);
		for (count = 0;count < 5;count++)
			printf("%hd\n", rand1());
		printf("please enter next seed (q to quit):\n");
	}
	printf("done\n");
	return 0;
}