#include<stdio.h>
#include<stdlib.h>
void sign_off(void);
void too_bad(void);
int main(void)
{
	int n;
	atexit(sign_off);
	puts("Exter an integre:");
	if (scanf("%d", &n) != 1)
	{
		puts("That's is not integer!");
		atexit(too_bad);
		exit(EXIT_FAILURE);
	}
	printf("%d is %s .\n", n, (n % 2 == 0) ? "even" : "odd");

	return 0;
}
void sign_off(void)
{
	puts("Thus terminates another magnificent program from");
	puts("SeeSaw Software");
}

void too_bad(void)
{
	puts("SeeSaw Software extends its hearfelt condolences");
	puts("to you upon the failure of your program.");
}