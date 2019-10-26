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
	int x[100];
	int y[100];
	int i;
	for (i = 0;i < 100;i++)
	{
		x[i] = rand() % 640;
		y[i] = rand() % 480;
	}

	while (!kbhit())
	{
		for (i = 0;i < 100;i++)
		{
			putpixel(x[i], y[i], BLACK);
			y[i] += 3;
		}
		for (i = 0;i < 100;i++)
		{
			if (y[i] >= 480)y[i] = 0;
			putpixel(x[i], y[i], WHITE);
		}
		Sleep(10);
	}
	getch();
	closegraph();
}