#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char ch;
	printf("Give me a letter of the alphabet,and i will give");
	printf("an animan name\nbegining with a letter.\n");
	printf("please type in a letter;type #to end my act.\n");
	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')continue;
		if (islower(ch))
			switch (ch)
			{
			case 'a':printf("argial,a wild sheep of Asia\n");break;
			case 'b':printf("babir,a wild pig of malay\n");break;
			case 'c':printf("coati,racooonlike mammal\n");break;
			case 'd':printf("desman,aquatic,molelike critter\n");break;
			case 'e':printf("echida,the spiny antese\n");break;
			case 'f':printf("fidher,the spiny sntester\n");break;
			default:printf("Thant is a stumper!\n");
			}
		else
			printf("I recognize only lower letter!\n");
		
		printf("please type another letter or a #.\n");
	}
	printf("Bye.\n");
	getchar();
	getchar();
	return 0;
}