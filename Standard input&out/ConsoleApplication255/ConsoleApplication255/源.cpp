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
	int x;
	while (1)
	{
		for ( x = 100;x < 640;x += 20)
		{
			setcolor(YELLOW);
			setfillcolor(GREEN);
			fillcircle(x, 100, 20);
			Sleep(100);
			setcolor(BLACK);
			setfillcolor(BLACK);
			fillcircle(x, 100, 20);
		}
		for (;x > 0;x -= 20)
		{
			setcolor(YELLOW);
			setfillcolor(GREEN);
			fillcircle(x, 100, 20);
			Sleep(100);
			setcolor(BLACK);
			setfillcolor(BLACK);
			fillcircle(x, 100, 20);
		}

	}
	getch();
	closegraph();
}
