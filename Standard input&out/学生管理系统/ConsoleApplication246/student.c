#include<stdio.h>
#include<stdlib.h>
#include"list.h"
int main(void)
{
	List students;
	int n;
	InitializeList(&students);
	if (ListIsFull(&students))
	{
		fprintf(stderr, "NO memory!");
		exit(1);
	}
	ReadList(&students);
	menu();  //�˵��б�
	while (scanf("%d", &n)==1)
	{
		while (getchar() != '\n')continue;
		switch (n)
		{
		case 1:ListInsertItem(&students);break;  //����
		case 2:ListUpdate(&students);break;      //�޸�
		case 3:ListDeleteItem(&students);break;  //ɾ��
		case 4:show(&students);break;            //���
		case 5:ListSearch(&students);break;      //��ѯ
		case 6:ListItemCount(&students);break;   //��ʾѧ������
		default:puts("Bye!");WriteList(&students);EmptyTheList(&students);exit(1);         //�˳�
		}
		menu();
	}
	getchar();
	return 0;
}