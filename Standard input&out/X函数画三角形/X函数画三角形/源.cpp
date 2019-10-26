#include<graphics.h>
#include<conio.h>
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };
#define PI 3.14
void trigle(int x, int y, int c);
void main()
{
	initgraph(640, 480);
	for(int x=0;x<640;x+=10)
		for (int y=0;y<480;y+=10)
		{
			trigle(x, y, RGB(x * 255 / 640, y * 255 / 480,0));
		}
	getch();
	closegraph();
}

void trigle(int x, int y, int c)
{
	setlinecolor(c);
	line(x, y, x + 50, y);
	line(x, y, x, y + 50);
	line(x, y + 50, x + 50, y);
}