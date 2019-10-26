#include<stdio.h>
int main()
{
	int a[8], i, max;
	printf("please enter number:");
	for (i = 0;i < 8;i++)
		scanf("%d", &a[i]);
	max = Maxsum(a, 8);
	printf("max=%d", max);
	getchar();
	return 0;
}
int Maxsum(int a[], int N)
{
	int thissum, maxsum;
	int i;
	thissum = maxsum = 0;
	for (i = 0;i < N;i++)
	{
		thissum += a[i];
		if (thissum > maxsum)maxsum = thissum;
		else
			if (thissum < 0)
				thissum = 0;
	}
	return maxsum;
}