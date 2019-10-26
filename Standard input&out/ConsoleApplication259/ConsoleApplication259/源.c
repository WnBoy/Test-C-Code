#include <stdio.h>
typedef struct BoundedArray
{
	int size;
	int *arr;
}boundedarray;

boundedarray * pizzaOrder(int numOfOrders, int size, int *orders);
boundedarray t;
int main(void)
{
	int nnumOfOrders=6;
	int size=3;
	int orders[] = { -11,-2,19,37,64,-18 };
	boundedarray *p;
	p=pizzaOrder(nnumOfOrders, size, orders);
	for (int i=0;i<(*p).size;i++)
	{
		printf("%d", (*p).arr[i]);
	}
}
boundedarray * pizzaOrder(int numOfOrders, int size, int *orders)
{
	t.arr = NULL;
	t.arr = 0;
	int i;
	int j;
	for (i=0;i<numOfOrders-size+1;i++)
	{
		for (j=i;j<i+3;j++)
		{
			if (orders[j] < 0)
				t.arr[i] = orders[j];	
			else t.arr[i] = 0;
			break;
		}
	}
	t.size = numOfOrders - size + 1;
	return &t;
}