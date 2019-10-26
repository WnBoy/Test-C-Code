#include<stdio.h>
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };

#include<graphics.h>
#include<conio.h>
int main()
{
	initgraph(640, 480);
	line(200, 240, 440, 240);
	line(321, 120, 320, 360);
	getchar();
	closegraph();
}