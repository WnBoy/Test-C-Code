#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	double*ptr;
	int max;
	int number;
	int i=0;
	puts("Please enter max:");
	scanf("%d", &max);
	ptr = (double*)malloc(max*sizeof(double));
	if (ptr == NULL)
	{
		puts("û�з����ڴ�");
		exit(EXIT_FAILURE);
	}
	puts("�������ݣ�");
	while (i < max&&scanf("%lf", ptr[i]) == 1)
		i++;
	puts("�����");
	number = i;
	for (i = 0;i < number;i++)
	{
		printf("%7.2f", ptr[i]);
		if (i % 7 == 6)putchar('\n');
	}
	if (i % 7 != 0)
		putchar('\n');
	puts("Done.");
	free(ptr);
	getchar();
	return 0;
}