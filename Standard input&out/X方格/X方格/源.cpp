#include<graphics.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>
#include <stdio.h>
#include <tchar.h>
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };

void main()
{
	int x, y;
	TCHAR num[4];
	srand((unsigned)time(NULL));
	initgraph(640, 480);
	for(x=0;x<=480;x+=30)
		for (y = 0;y <= 240;y += 30)
		{
			line(x, 0, x, 240);
			line(0, y, 480, y);
		}
	bool cell[16][8];
	for (x = 0;x < 16;x += 30)
		for (y = 0;y < 8;y += 30)
			cell[x][y] = false;
	for (int i = 1;i <= 128;i++)
	{
		do 
		{
			x = rand() % 16;
			y = rand() % 8;
		} while (cell[x][y]==true);
		cell[x][y] = true;
		_stprintf(num, _T("%d"), i);
		outtextxy(x * 30, y * 30, num);
	}
	getch();
	closegraph();
}