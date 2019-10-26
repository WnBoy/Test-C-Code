#include <graphics.h>
#include <conio.h>
#include <math.h>
#include<stdio.h>
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };
#define PI 3.14159265359
void Draw(int hour, int minute, int second);
void kedu();
int main()
{
	initgraph(640, 480);
	circle(320, 240, 2);
	setcolor(YELLOW);
	setlinestyle(PS_SOLID, 5);
	circle(320, 240, 160);
	setlinecolor(BROWN);
	circle(320, 240, 60);
	setcolor(LIGHTMAGENTA);
	outtextxy(296, 310, _T("Wnlife"));
	kedu();//���̶�
	setwritemode(R2_XORPEN);
	SYSTEMTIME ti;
	while (!kbhit())
	{
		GetLocalTime(&ti);
		Draw(ti.wHour, ti.wMinute, ti.wSecond);
		Sleep(1000);
		Draw(ti.wHour, ti.wMinute, ti.wSecond);
	}
	getch();
	closegraph();
}

void Draw(int hour, int minute, int second)
{
	double a_hour, a_min, a_sec;//����ֵ
	int x_hour, y_hour, x_min, y_min, x_sec, y_sec, x_e_sec, y_e_sec;

	//����ʱ���֡���Ļ���ֵ
	a_sec = second * 2 * PI / 60;
	a_min = minute * 2 * PI / 60 + a_sec / 60;
	a_hour = hour * 2 * PI / 60 + a_min / 12;

	//����ʱ��ĩ�˵�����
	x_sec = 320 + (int)(120 * sin(a_sec));
	y_sec = 240 - (int)(120 * cos(a_sec));
	x_e_sec= 320 - (int)(40 * sin(a_sec));
	y_e_sec= 240 + (int)(40 * cos(a_sec));
	x_min = 320 + (int)(100 * sin(a_min));
	y_min = 240 - (int)(100 * cos(a_min));
	x_hour = 320 + (int)(70 * sin(a_hour));
	y_hour = 240 - (int)(70 * cos(a_hour));

	//��ʱ��
	setlinestyle(PS_SOLID, 10, NULL);
	setlinecolor(WHITE);
	line(320, 240, x_hour, y_hour);

	//������
	setlinestyle(PS_SOLID, 6, NULL);
	setlinecolor(GREEN);
	line(320, 240, x_min, y_min);

	//������
	setlinestyle(PS_SOLID, 2, NULL);
	setlinecolor(RED);
	line(x_e_sec, y_e_sec, x_sec, y_sec);
}

void kedu()
{
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 3);
	double j;
	int s_x, s_y, e_x, e_y;
	for (j = 0; j < 2 * PI;	j += (PI / 6))
	{
		s_x = (int)(320 + 160 * sin(j));
		s_y = (int)(240 - 160 * cos(j));
		e_x = (int)(320 + 150 * sin(j));
		e_y = (int)(240 - 150 * cos(j));
		line(s_x, s_y, e_x, e_y);
	}
}