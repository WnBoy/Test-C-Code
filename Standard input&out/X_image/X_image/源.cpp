#include<graphics.h>
#include<conio.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };

void main()
{
	int y=0;
	initgraph(640, 500);
	IMAGE img;
	loadimage(&img, _T("E:\\test\\timg (2).jpg"),100,100);
	while (!kbhit())
	{
		putimage(0, y, &img);
		clearrectangle(0, y, 100, 100);
		y += 100;
		if (y >= 500)
		{
			clearrectangle(0, y, 100, 100);
			y = 0;
		}
		
		Sleep(1000);
	}


	


	getch();
	closegraph();
}