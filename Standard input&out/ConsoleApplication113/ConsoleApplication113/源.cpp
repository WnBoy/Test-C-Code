
#include<graphics.h>                      //绘图库头文件，绘图语句需要
#include<conio.h>                           //在控制台输入输出文件
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };
int main()
{
	initgraph(640, 480);                //初始化一个640*480的窗口，
	line(100, 100, 200, 200);        //画一条从点(100,100)到点(200,200)的直线
	line(100, 200, 200, 100);
	getch();                                  //按任意键
	closegraph();                         //关闭绘图窗口
	return 0;
}