#include<graphics.h>
#include<conio.h>
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };
#define PI 3.14
void main(void)
{
	initgraph(640, 480);
	int x=320;
	char c='d';
	setcolor(YELLOW);
	setfillcolor(GREEN);
	fillcircle(x, 240, 20);
	while (1)
	{
		if (kbhit())
		{
			c = getch();
				setcolor(BLACK);
				setfillcolor(BLACK);
				fillcircle(x, 240, 20);
				switch (c)
				{
				case 'a':x -= 2;break;
				case 'd':x += 2;break;
				case 27:break;
				}
				setcolor(YELLOW);
				setfillcolor(GREEN);
				fillcircle(x, 240, 20);
				Sleep(50);

		}
		else
		{
			setcolor(BLACK);
			setfillcolor(BLACK);
			fillcircle(x, 240, 20);
			if (c == 'a')x -= 2;
			if (c == 'd')x += 2;
			if (c == 27)break;
			setcolor(YELLOW);
			setfillcolor(GREEN);
			fillcircle(x, 240, 20);
			Sleep(50);
		}
	}
	getch();
	closegraph();
}
