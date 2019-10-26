#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<time.h>
//一些键值的定义
#define PI 3.141592653
#define UP 0x4800
#define DOWN 0x5000
#define ESC 0x11b
#define TAB 0xf09

int keyhandle(int, int);/*键盘按键判断*/
int timeupchange(int);/*处理上移按键*/
int timedownchange(int);/*处理下移按键*/
int digithour(double);/*double hour to int*/
int digitsec(double);
int digitmin(double);
void digitclock(int, int, int);/*在指定位置显示时钟或分钟或秒钟*/
void drawcursor(int);/*绘制一个光标*/
void clearcursor(int);/*消除一个光标*/
void clockhandle();/*时钟处理*/
void digitAclock();/*闹钟数字显示*/

double h, m, s;
double x, x1, x2, y, y1, y2;
struct time t[1];
struct AlarmClock/*定义闹钟结构体变量*/
{
	int hc;
	int mc;
	int sc;
}Alarm;

int main()
{
	int driver, mode = 0, i, j;
	driver = DETECT;
	initgraph(&driver, &mode, "");
	setlinestyle(0, 0, 3);
	setbkcolor(8);
	setcolor(RED);
	/*时钟外围主体框架*/
	rectangle(52, 11, 583, 431);
	rectangle(44, 28, 592, 413);
	setwritemode(0);
	/*时钟标题*/
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	outtextxy(280, 15, "MyColck");
	/*画一个光标*/
	line(136, 269, 136, 285);

	/*shu zi shi zhong kuang jia*/
	line(95, 262, 250, 262);
	line(95, 297, 250, 297);
	arc(95, 280, 90, 270, 17);
	arc(250, 280, 270, 90, 17);
	setcolor(5);
	/*作时分秒之间的分隔符*/
	for (i = 146;i <= 197;i += 51)
		for (j = 274;j <= 281;j += 7)
		{
			setlinestyle(0, 0, 3);
			circle(i, j, 1);
		}
	/*在时钟中心画一个圆作为时钟的转轴*/
	setcolor(YELLOW);
	circle(178, 151, 2);


	/*==================================================*/
	/*小时点数*/
	for (i = 0, m = 0, h = 0;i <= 11;i++, h++)
	{
		x = 88 * sin((h * 60 + m) / 360 * PI) + 178;
		y = 151 - 88 * cos((h * 60 + m) / 360 * PI);
		setlinestyle(0, 0, 3);
		setcolor(14);
		circle(x, y, 1);
	}
	/*分或秒点数*/
	for (i = 0, m = 0;i <= 59;m++, i++)
	{
		x = 88 * sin(m / 30 * PI) + 178;
		y = 151 - 88 * cos(m / 30 * PI);
		setlinestyle(0, 0, 1);
		setcolor(3);
		circle(x, y, 1);
	}
	/*在时钟上打印12，3，6，9数字*/
	outtextxy(98, 148, "9");
	outtextxy(250, 148, "3");
	outtextxy(170, 70, "12");
	outtextxy(175, 225, "6");


	/*帮助界面*/
	setcolor(GREEN);
	outtextxy(131, 310, "H E L P");
	outtextxy(84, 328, "Tab :Cursor move");
	outtextxy(84, 348, "Up  :Time ++");
	outtextxy(84, 368, "Down:Time --");
	outtextxy(84, 388, "Esc :Quit system!");
	outtextxy(312, 418, "Designed by Futuroscope&Joyce");

	/*绘制note的框架和字样*/
	rectangle(315, 101, 484, 381);
	rectangle(322, 86, 498, 387);
	rectangle(326, 244, 481, 279);/*闹钟数字显示框架*/
	line(378, 244, 378, 279);
	line(430, 244, 430, 279);
	setcolor(1);
	outtextxy(370, 111, "N O T E");
	setcolor(YELLOW);
	outtextxy(330, 135, "You can set an ala-");
	outtextxy(330, 145, "rm colck here!");
	setcolor(8);
	outtextxy(354, 298, "ATTENTION!");

	clockhandle();
	closegraph();
	return 0;
}


void clockhandle()
{
	int k = 0, count;
	/*初始化闹钟*/
	Alarm.hc = 0;
	Alarm.mc = 0;
	Alarm.sc = 0;
	setcolor(RED);
	digitAclock(336, 254, Alarm.hc)；
		digitAclock(388, 254, Alarm.mc);
	digitAclock(440, 254, Alarm.sc);
	setcolor(15);/*白色时针*/
	gettime(t);
	setwritemode(1);
	/*开始循环，直到按ESC*/
	for (count = 2;k != ESC;)
	{

		/*声音模拟*/
		sound(500);
		delay(700);
		sound(200);
		delay(300);
		nosound();

		s = t[0].ti_sec;
		m = t[0].ti_min;
		h = t[0].ti_hour;

		/*draw hour r=50 ,white*/
		setcolor(15);
		x = 50 * sin((h * 60 + m) / 360 * PI) + 178;
		y = 151 - 50 * cos((h * 60 + m) / 360 * PI);
		line(178, 151, x, y);

		/*draw minuite r=78 lightblue*/
		setcolor(9);
		x1 = 78 * sin(m / 30 * PI) + 178;
		y1 = 151 - 78 * cos(m / 30 * PI);
		line(178, 151, x1, y1);

		/*draw second r=85 lightred*/
		setcolor(12);
		x2 = 85 * sin(s / 30 * PI) + 178;
		y2 = 151 - 85 * cos(s / 30 * PI);
		line(178, 151, x2, y2);

		while (t[0].ti_sec == s&&t[0].ti_min == m&&t[0].ti_hour == h)
		{
			gettime(t);/*get system's time*/
			if (bioskey(1) != 0)
			{
				k = bioskey(0);
				count = keyhandle(k, count);
				if (count == 8)
					count = 1;
			}
		}/*whlie end*/

		setcolor(15);
		/*在数字框中显示数字时、分、秒,white*/
		digitclock(105, 275, digithour(h));
		digitclock(160, 275, digitmin(m));
		digitclock(215, 275, digitsec(s) + 1);

		/*异或操作，在原来的地方用相同的颜色画相同的秒针来擦除*/
		setcolor(15);
		x = 50 * sin((h * 60 + m) / 360 * PI) + 178;
		y = 151 - 50 * cos((h * 60 + m) / 360 * PI);
		line(178, 151, x, y);

		setcolor(9);
		x1 = 78 * sin(m / 30 * PI) + 178;
		y1 = 151 - 78 * cos(m / 30 * PI);
		line(178, 151, x1, y1);

		setcolor(12);
		x2 = 85 * sin(s / 30 * PI) + 178;
		y2 = 151 - 85 * cos(s / 30 * PI);
		line(178, 151, x2, y2);

		/*Alarm colck*/
		if (Alarm.hc == h&&Alarm.mc == m&&Alarm.sc == s)
		{
			Alarm.sc++;
			setwritemode(1);
			setcolor(YELLOW);
			setlinestyle(0, 0, 3);
			rectangle(315, 101, 484, 381);
			rectangle(322, 86, 498, 387);
			setlinestyle(0, 0, 1);
			outtextxy(370, 111, "N O T E");
			setcolor(RED);
			outtextxy(330, 135, "You can set an ala-");
			outtextxy(330, 145, "rm colck here!");
			outtextxy(254, 298, "ATTENTION!");
			delay(2000);
		}

	}/*for end*/
}


int keyhandle(int key, int count)
{
	switch (key)
	{
	case UP:timeupchange(count - 1);break;
	case DOWN:timedownchange(count - 1);break;
	case TAB:setcolor(YELLOW);drawcursor(count);clearcursor(count);count++;break;
	}
	return count;
}


int timeupchange(int count)/*上键处理*/
{
	if (count == 1)
	{
		t[0].ti_hour++;
		if (t[0].ti_hour == 24) t[0].ti_hour = 0;
		settime(t);
	}
	if (count == 2)
	{
		t[0].ti_min++;
		if (t[0].ti_min == 60)
		{
			t[0].ti_hour++;
			if (t[0].ti_hour == 24)
				t[0].ti_hour = 0;
			t[0].ti_min = 0;
		}
		settime(t);
	}
	if (count == 3)
	{
		t[0].ti_sec++;
		if (t[0].ti_sec == 60)
		{
			t[0].ti_min++;
			if (t[0].ti_min == 60)
			{
				t[0].ti_hour++;
				if (t[0].ti_hour == 24)
					t[0].ti_hour = 0;
				t[0].ti_min = 0;
			}
			t[0].ti_sec = 0;
		}
		settime(t);
	}

	/*闹钟*/
	{
		if (count == 4)
		{
			Alarm.hc++;
			if (Alarm.hc == 24)
				Alarm.hc = 0;
		}

		if (count == 5)
		{
			Alarm.mc++;
			if (Alarm.mc == 60)
				Alarm.mc = 0;
		}

		if (count == 6)
		{
			Alarm.sc++;
			if (Alarm.sc == 60)
				Alarm.sc = 0;
		}
		setcolor(RED);
		digitAclock(336, 254, Alarm.hc)；
			digitAclock(388, 254, Alarm.mc);
		digitAclock(440, 254, Alarm.sc);
	}
}


int timedownchange(int count)/*下键处理*/
{
	if (count == 1)
	{

		if (t[0].ti_hour == 0) t[0].ti_hour = 24;
		t[0].ti_hour--;
		settime(t);
	}
	if (count == 2)
	{

		if (t[0].ti_min == 0)
		{
			if (t[0].ti_hour == 0)
				t[0].ti_hour = 24;
			t[0].ti_hour--;
			t[0].ti_min = 60;
		}
		t[0].ti_min--;
		settime(t);
	}
	if (count == 3)
	{
		if (t[0].ti_sec == 0)
		{
			if (t[0].ti_min == 0)
			{
				if (t[0].ti_hour == 0)
					t[0].ti_hour = 24;
				t[0].ti_min = 60;
				t[0].ti_hour--;
			}
			t[0].ti_sec = 60;
			t[0].ti_min--;
		}
		t[0].ti_sec--;
		settime(t);
	}

	{
		if (count == 4)
		{
			Alarm.hc--;
			if (Alarm.hc<0)
				Alarm.hc = 23;
		}

		if (count == 5)
		{
			Alarm.mc--;
			if (Alarm.mc<0)
				Alarm.mc = 59;
		}

		if (count == 6)
		{
			Alarm.sc--;
			if (Alarm.sc<0)
				Alarm.sc = 59;
		}
		setcolor(RED);
		digitAclock(336, 254, Alarm.hc)；
			digitAclock(388, 254, Alarm.mc);
		digitAclock(440, 254, Alarm.sc);
	}
}


void digitclock(int x, int y, int clock)/*数字时钟*/
{
	char buffer1[10];
	setfillstyle(0, 2);
	bar(x, y, x + 15, 290);
	if (clock >= 60)
		clock = 0;
	sprintf(buffer1, "%d", clock);
	outtextxy(x, y, buffer1);
}

void digitAclock(int x, int y, int clock)
{
	char buffer2[10];
	setfillstyle(0, 2);
	bar(x, y, x + 15, 270);
	if (clock >= 60)
		clock = 0;
	sprintf(buffer2, "%d", clock);
	outtextxy(x, y, buffer2);

}


int digithour(double h)/*double hour to int*/
{
	int i;
	for (i = 0;i <= 23;i++)
	{
		if (h == i)
			return i;
	}
}

int digitmin(double m)/*double minuite to int*/
{
	int i;
	for (i = 0;i <= 59;i++)
	{
		if (m == i)
			return i;
	}
}

int digitsec(double s)/*double second to int*/
{
	int i;
	for (i = 0;i <= 59;i++)
	{
		if (s == i)
			return i;
	}
}


/*绘画光标*/
void drawcursor(int count)
{
	switch (count)
	{
	case 1:line(136, 269, 136, 285);break;
	case 2:line(188, 269, 188, 285);break;
	case 3:line(244, 269, 244, 285);break;
	case 4:line(367, 254, 367, 270);break;
	case 5:line(418, 254, 418, 270);break;
	case 6:line(469, 254, 469, 270);break;

	}
}

/*清除光标*/
void clearcursor(int count)
{
	switch (count)
	{
	case 2:line(136, 269, 136, 285);break;
	case 3:line(188, 269, 188, 285);break;
	case 4:line(244, 269, 244, 285);break;
	case 5:line(367, 254, 367, 270);break;
	case 6:line(418, 254, 418, 270);break;
	case 1:line(469, 254, 469, 270);break;
	}
}