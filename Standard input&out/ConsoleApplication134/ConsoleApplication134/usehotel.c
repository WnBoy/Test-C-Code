#include<stdio.h>
#include"hotel.h"
int main(void)
{
	int nights;
	double hotel_rate;
	int code;
	while ((code = menu()) != QUIT)
	{
		switch (code)
		{
		case 1:hotel_rate = HOTEL1;break;
		case 2:hotel_rate = HOTEL2;break;
		case 3:hotel_rate = HOTEL3;break;
		case 4:hotel_rate = HOTEL4;break;
		defaule:hotel_rate = 0.0;printf("Oops!\n");break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("BYBY!");
	getchar();
	getchar();
	return 0;
}