#include<stdio.h>
void put1(const char*);
int put2(const char*);
int main(void)
{
	int t;
	put1("djaisdladjla");
	put1("sajdlajdsla\n");
	t=put2("aaaaaaa.");
	printf("djaljd %d asju.\n", t);
	getchar();
	return 0;
}

void put1(const char*s1)
{
	while (*s1)
		putchar(*s1++);
}

int put2(const char*s2)
{
	int count=0;
	while (*s2++)
	{
		putchar(*s2++);
		count++;
	}
	putchar('\n');
	return count;
}