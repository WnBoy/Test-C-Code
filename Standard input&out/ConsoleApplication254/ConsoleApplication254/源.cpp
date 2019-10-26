#include<graphics.h>
#include<conio.h>
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };
void main()
{
	initgraph(640, 480);
	setlinestyle(PS_SOLID, 10);
	setlinecolor(GREEN);
	rectangle(100, 100, 200, 200);
	setwritemode(R2_XORPEN);
	setcolor(RED);
	line(50, 0, 200, 300);
	getch();
	line(50, 0, 200, 300);
	getch();
	closegraph();
}