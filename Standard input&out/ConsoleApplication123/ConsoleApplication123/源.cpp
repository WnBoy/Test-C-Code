#include <graphics.h>      // ������Ҫ�������ͼ�ο�
#include <conio.h>
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };

void main()
{
	
	initgraph(640, 480);   // ����� TC ��������
	setlinecolor(0xff0000);
	circle(200, 200, 100); // ��Բ��Բ��(200, 200)���뾶 100
	getch();               // �����������
	closegraph();          // �ر�ͼ�ν���
}