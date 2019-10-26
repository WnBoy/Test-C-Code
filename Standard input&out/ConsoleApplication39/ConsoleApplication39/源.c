#include<stdio.h>
int main()
{
	int a=100, b=10, *s1, *s2;
	s1 = &a;
	s2 = &b;
	printf("a=%d,b=%d\n", a, b);
	printf("*s1=%d,*s2=%d\n", *s1, *s2);
	getchar();
	return 0;
}