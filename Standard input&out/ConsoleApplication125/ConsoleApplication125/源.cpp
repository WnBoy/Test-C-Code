#include <graphics.h>
#include <conio.h>
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };

void main()
{
	// ������ͼ����
	initgraph(640, 480);

	// ����������(ͨ������������)
	float H = 190;		// ɫ��
	float S = 1;		// ���Ͷ�
	float L = 0.7f;		// ����
	for (int y = 0; y < 480; y++)
	{
		L += 0.0005f;
		setlinecolor(HSLtoRGB(H, S, L));
		line(0, y, 639, y);
	}

	// ���ʺ�(ͨ��ɫ��������)
	H = 0;
	S = 1;
	L = 0.5f;
	setlinestyle(PS_SOLID, 2);		// �����߿�Ϊ 2
	for (int r = 400; r > 344; r--)
	{
		H += 5;
		setlinecolor(HSLtoRGB(H, S, L));
		circle(500, 480, r);
	}

	// ��������˳�
	getch();
	closegraph();
}