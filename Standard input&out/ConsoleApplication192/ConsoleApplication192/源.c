#include<stdio.h>
void to_binary(unsigned long n);
int main(void)
{
	unsigned long number;
	printf("Please enter a number:");
	while (scanf("%ul", &number) == 1)
	{
		printf("Bonary equivalent:");
		to_binary(number);
		putchar('\n');
		printf("Please enter a number:");
	}
	printf("Done.\n");
	
	return 0;
}

void to_binary(unsigned long n)
{
	int r;
	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar('0' + r);
	return 0;
}