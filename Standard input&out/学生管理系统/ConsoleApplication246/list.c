#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"list.h"

void menu(void)    
{
	printf("\n\n\n\n\n\n");
	puts("\t\t|-------------学生管理里系统------------|");
	puts("\t\t|\t 1.输入成绩.                    |");
	puts("\t\t|\t 2.修改成绩.                    |");
	puts("\t\t|\t 3.删除信息.                    |");
	puts("\t\t|\t 4.输出信息.                    |");
	puts("\t\t|\t 5.查询信息.                    |");
	puts("\t\t|\t 6.显示学生数量.                |");
	puts("\t\t|\t other number is quit.          |");
	puts("\t\t|---------------------------------------|");
	puts("\t\t\t\tchose(1-6):");
}

void InitializeList(List*plist)  //初试化链表
{
	*plist = NULL;
}

bool ListIsEmpty(const List*plist) //查看链表是否是空的
{
	if (*plist == NULL)return true;
	else return false;
}

bool ListIsFull(const List*plist)  //查看能链表是否满了
{
	List pt;
	bool full;
	pt = (List)malloc(sizeof(Node));
	if (pt == NULL)full = true;
	else full=false;
	free(pt);
	return full;
}

void ReadList(List*plist)  //从文件中读取历史数据          方案1
{
	puts("正在获取历史数据...");
	List current;
	List pre;
	FILE* fp;
	while ((fp = fopen("student.dat", "rb")) == NULL)
	{
		fprintf(stderr, "Can't open students.dat file");
		exit(1);
	}
	rewind(fp);
	while (!feof(fp))
	{
		current = (List)malloc(sizeof(Node));
		if (current == NULL)
		{
			puts("No memory!");
			exit(EXIT_FAILURE);
		}
		current->next = NULL;
		fread(&(current->item), sizeof(Item), 1, fp);
		if (feof(fp)) { free(current);break; }
		if (*plist == NULL)
			*plist= current;
		else pre->next = current;
		pre = current;
	}
	fclose(fp);
	puts("历史数据已经获取.");
}

//void ReadList(List*plist)  //从文件中读取历史数据          方案2
//{
//	puts("正在获取历史数据...");
//	List current;
//	List pre = NULL;
//	FILE* fp;
//	while ((fp = fopen("student.dat", "rb")) == NULL)
//	{
//		fprintf(stderr, "Can't open students.dat file");
//		exit(1);
//	}
//	rewind(fp);
//	while (1)
//	{
//		current = (List)malloc(sizeof(Node));
//		if (current == NULL)
//		{
//			puts("No memory!");
//			exit(EXIT_FAILURE);
//		}
//		if (!fread(&(current->item), sizeof(Item), 1, fp))
//		{
//			free(current);
//			break;
//		}
//		if (*plist == NULL)
//			*plist = current;
//		else
//			pre->next = current;
//		current->next = NULL;
//		pre = current;
//	}
//	fclose(fp);
//	puts("历史数据已经获取.");
//}


void WriteList(const List*plist)     //存储数据
{
	List ptr=*plist;
	puts("正在存储数据...");
	FILE*fp;
	while ((fp = fopen("student.dat", "wb")) == NULL)
	{
		fprintf(stderr, "Can't open students.dat file");
		exit(2);
	}
	while (ptr != NULL)
	{
		fwrite(&(ptr->item), sizeof(Item), 1, fp);
		ptr = ptr->next;
	}
	puts("存储数据成功！");
	fclose(fp);
}

void ListItemCount(const List*plist)  //学生数目
{
	List pt = *plist;
	unsigned int n=0;
	while (pt != NULL)
	{
		n++;
		pt = pt->next;
	}
	printf("This list have %d students.", n);
}

void ListSearch(const List*plist)  //查找
{
	List pt = *plist;
	int number;
	int flag=1;       //标记
	puts("Please enter this sudent's number:");
	scanf("%d", &number);
	while (pt != NULL&&flag)
	{
		if (pt->item.number == number)
		{
			printf("This student name is %s\n,number is %d\n,grade is %f.\n",
				pt->item.name, pt->item.number, pt->item.grade);
			flag = 0;  //找到标记为0
		}
		else
			pt = pt->next;
	}
	if (flag)printf("No found！");
}

void ListInsertItem(List*plist)   //输入信息
{
	List pt=*plist;
	List pre;
	List r;
	int number;
	if (ListIsFull(plist))
	{
		puts("This list is full.");
		return;
	}
	puts("Please enter number:");
	scanf("%d", &number);
	while (pt != NULL)
	{
		if (pt->item.number == number)
		{
			puts("This list have this number,please inpit other number.");
			return;
		}
		else { pre = pt; pt = pt->next;}
	}
	r = (List)malloc(sizeof(Node));
	if (r == NULL) {
		puts("NO memory!");
		exit(3);
	}
	r->next = NULL;
	if (*plist == NULL)
		*plist = r;
	else
		pre->next = r;
	(r->item).number = number;
	puts("Please enter this student's name:");
	while (getchar() != '\n')continue;
	gets((r->item).name);
	puts("Please enter this student's grade:");
	scanf("%f", &(r->item.grade));
}

void ListUpdate(const List*plist) //修改
{
	List pt = *plist;
	int number;
	int flag = 1;
	puts("Please enter this student's number:");
	scanf("%d", &number);
	while (pt != NULL&&flag)
	{
		if (pt->item.number == number)
		{
			puts("Please enter name:");
			gets(pt->item.name);
			puts("Please enter grade:");
			scanf("%f", &pt->item.grade);
			flag = 0;
		}
		else pt = pt->next;
	}
	if (flag)puts("Don't find this number!");
}

void ListDeleteItem(List*plist)  //删除
{
	List pt = *plist;
	List pr = *plist;
	int number;
	int flag=1;
	puts("Please enter this student's number:");
	scanf("%d", &number);
	while (pt != NULL&&flag)
	{
		if (pt->item.number == number)
		{
			if (pt == *plist)
			{ 
				*plist = pt->next;
			    free(pt); 
			}
			else
			{
				pr->next = pt->next;
				free(pt);
			}
			flag = 0;
		}
		else
		{
			pr = pt;
		    pt = pt->next;
		}
	}
	if (flag)puts("No find this student!");

}

void show(const List *plist)  //输出
{
	List pt =  *plist;
	if (pt == NULL)puts("This list is empty!");
	else
	while (pt != NULL)
	{
		puts("Here is the students list:");
		printf("Name is :%s\nNumber is :%d\nGrade is :%f\n",
			pt->item.name,pt->item.number,pt->item.grade);
		pt = pt->next;
	}
}

void EmptyTheList(List*plist)  //清空链表
{
	List pt = *plist;
	while (*plist != NULL)
	{
		pt =(*plist)->next;
		free(*plist);
		*plist = pt;
	}
}