#include <stdio.h>
typedef struct BoundedArray
{
	int size;
	int *arr;
}boundedarray;
boundedarray t;
boundedarray * pizzaOrder(int numOfOrders, int size, int *orders);
int main(void)
{
	int nnumOfOrders = 6;
	int size = 3;
	int orders[] = { -11,-2,19,37,64,-18 };
	boundedarray *p;
	p = pizzaOrder(nnumOfOrders, size, orders);
	for (int i = 0;i < (*p).size;i++)
	{
		printf("%d", (*p).arr[i]);
	}
	getchar();
	return 0;
}
boundedarray * pizzaOrder(int numOfOrders, int size, int *orders)
{
	
	for (int k = 0;k < numOfOrders - size;k++)
	{
		t.arr[k] = 0;
	}
	t.size = 0;
	for (int i = 0;i < numOfOrders - size + 1;i++)
	{
		for ( int j = i; j < i+3; j++)
		{
			if (orders[j] < 0)
			{
				t.arr[i] = orders[j];
				break;
			}
		}
	}
	t.size = numOfOrders - size + 1;
	return &t;
}