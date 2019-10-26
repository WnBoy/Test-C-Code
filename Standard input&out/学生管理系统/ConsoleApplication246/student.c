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
	menu();  //菜单列表
	while (scanf("%d", &n)==1)
	{
		while (getchar() != '\n')continue;
		switch (n)
		{
		case 1:ListInsertItem(&students);break;  //插入
		case 2:ListUpdate(&students);break;      //修改
		case 3:ListDeleteItem(&students);break;  //删除
		case 4:show(&students);break;            //输出
		case 5:ListSearch(&students);break;      //查询
		case 6:ListItemCount(&students);break;   //显示学生数量
		default:puts("Bye!");WriteList(&students);EmptyTheList(&students);exit(1);         //退出
		}
		menu();
	}
	getchar();
	return 0;
}