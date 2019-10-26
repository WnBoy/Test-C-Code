#include<stdio.h>
#include<stdlib.h>
int *make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void)
{
	int*pa;
	int size;
	int value;
	printf("Enter the number of elements:");
	scanf("%d", &size);
	while (size > 0)
	{
		printf("Enter the initialization value:");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of element(<1 to quit):");
		scanf("%d", &size);
	}
	printf("Done.\n");
	return 0;
}
int *make_array(int elem, int val)
{
	int *c;
	int i;
	c = (int*)malloc(elem * sizeof(int));
	for (i = 0;i < elem;i++)
		c[i] = val;
	return c;
}
void show_array(const int ar[], int n)
{
	int j;
	for (j = 0;j < n;j++)
	{
		printf("%3d", ar[j]);
		if (j % 8 == 7)putchar('\n');
	}
	putchar('\n');
}