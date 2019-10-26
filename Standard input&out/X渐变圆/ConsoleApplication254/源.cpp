#include<graphics.h>
#include<conio.h>
#include<math.h>
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };
#define PI 3.14
void main(void)
{
	initgraph(640,480);
	int x, y, c;
	int r = 200;
	double a;
	for (a=0;a<2*PI;a+=0.0001)
	{
		x = (int)(r*cos(a) + 320 + 0.5);
		y = (int)(r*sin(a) + 240 + 0.5);
		c = (int)(a * 255 / (2 * PI) + 0.5);
		setcolor(RGB(0, c, 0));
		line(320, 240, x, y);
	}
	getch();
	closegraph();
}
