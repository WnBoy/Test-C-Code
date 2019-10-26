#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<graphics.h>
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };
#include <conio.h>
void main()
{
	srand((unsigned)time(NULL));
	initgraph(640, 480);
	int x, y, c;
	while (!kbhit())
	{
		x = rand() % 640;
		y = rand() % 480;
		c = RGB(rand() % 255, rand() % 255, rand() % 255);
		putpixel(x, y, c);
	}
	getch();
	closegraph();
}