
#include<graphics.h>                      //��ͼ��ͷ�ļ�����ͼ�����Ҫ
#include<conio.h>                           //�ڿ���̨��������ļ�
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };
int main()
{
	initgraph(640, 480);                //��ʼ��һ��640*480�Ĵ��ڣ�
	line(100, 100, 200, 200);        //��һ���ӵ�(100,100)����(200,200)��ֱ��
	line(100, 200, 200, 100);
	getch();                                  //�������
	closegraph();                         //�رջ�ͼ����
	return 0;
}