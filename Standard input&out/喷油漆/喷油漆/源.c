/*喷油漆，计算需要的油漆的桶数*/
#include<stdio.h>
#define COVERAGE 200
int main(void)
{
	int sq_feet;
	int cans;
	printf("please enter number of square feet to be painted:\n");
	while (scanf("%d", &sq_feet) == 1)
	{
		cans = sq_feet / COVERAGE;
	    cans += (sq_feet % COVERAGE == 0) ? 0 : 1;
	    printf("you need %d %s of paint.\n", cans, cans == 1 ? "can" : "cans");
	    printf("enter next value(q to quit):");
    }
	return 0;
}
