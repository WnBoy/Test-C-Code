#include<stdio.h>
int main()
{
	void gg(int v[], int n);
	int s[10], i;
	for (i = 0;i < 10;i++)
		scanf("%d", s[i]);
	gg(s, 10);
	for (i = 0;i < 10;i++)
		printf("%d", s[i]);
	getchar();
	return 0;
}
void gg(int v[],int n)
{
	int gap, i, j, t;
	for(gap=n/2;gap>0;gap-=2)
		for(i=gap;i<n;i++)
			for (j = i - gap;j >= 0 && v[j] > v[j + gap];j -= gap)
			{
				t = v[j];
				v[j] = v[j + gap];
				v[j + gap] = t;
			}
}