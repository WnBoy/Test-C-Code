#include <graphics.h>      // 就是需要引用这个图形库
#include <conio.h>
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };

void main()
{
	
	initgraph(640, 480);   // 这里和 TC 略有区别
	setlinecolor(0xff0000);
	circle(200, 200, 100); // 画圆，圆心(200, 200)，半径 100
	getch();               // 按任意键继续
	closegraph();          // 关闭图形界面
}