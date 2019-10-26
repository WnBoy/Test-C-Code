#include<stdio.h>
int main()
{
	int num;
	printf("please enter num:");
	scanf("%d", &num);
	int t = perfectNumberCheck(num);
	if (t)
		printf("yes");
	else
		printf("no");
	getchar();
	getchar();
}

int perfectNumberCheck(int num) {
	int t=0;
	for (int i = 1;i <= num;i++) {
		if (num%i == 0)
			t = t + i;
	}
	return t == num ? 1 : -1;
}