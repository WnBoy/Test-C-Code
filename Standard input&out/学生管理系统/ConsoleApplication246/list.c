#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"list.h"

void menu(void)    
{
	printf("\n\n\n\n\n\n");
	puts("\t\t|-------------ѧ��������ϵͳ------------|");
	puts("\t\t|\t 1.����ɼ�.                    |");
	puts("\t\t|\t 2.�޸ĳɼ�.                    |");
	puts("\t\t|\t 3.ɾ����Ϣ.                    |");
	puts("\t\t|\t 4.�����Ϣ.                    |");
	puts("\t\t|\t 5.��ѯ��Ϣ.                    |");
	puts("\t\t|\t 6.��ʾѧ������.                |");
	puts("\t\t|\t other number is quit.          |");
	puts("\t\t|---------------------------------------|");
	puts("\t\t\t\tchose(1-6):");
}

void InitializeList(List*plist)  //���Ի�����
{
	*plist = NULL;
}

bool ListIsEmpty(const List*plist) //�鿴�����Ƿ��ǿյ�
{
	if (*plist == NULL)return true;
	else return false;
}

bool ListIsFull(const List*plist)  //�鿴�������Ƿ�����
{
	List pt;
	bool full;
	pt = (List)malloc(sizeof(Node));
	if (pt == NULL)full = true;
	else full=false;
	free(pt);
	return full;
}

void ReadList(List*plist)  //���ļ��ж�ȡ��ʷ����          ����1
{
	puts("���ڻ�ȡ��ʷ����...");
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
	puts("��ʷ�����Ѿ���ȡ.");
}

//void ReadList(List*plist)  //���ļ��ж�ȡ��ʷ����          ����2
//{
//	puts("���ڻ�ȡ��ʷ����...");
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
//	puts("��ʷ�����Ѿ���ȡ.");
//}


void WriteList(const List*plist)     //�洢����
{
	List ptr=*plist;
	puts("���ڴ洢����...");
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
	puts("�洢���ݳɹ���");
	fclose(fp);
}

void ListItemCount(const List*plist)  //ѧ����Ŀ
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

void ListSearch(const List*plist)  //����
{
	List pt = *plist;
	int number;
	int flag=1;       //���
	puts("Please enter this sudent's number:");
	scanf("%d", &number);
	while (pt != NULL&&flag)
	{
		if (pt->item.number == number)
		{
			printf("This student name is %s\n,number is %d\n,grade is %f.\n",
				pt->item.name, pt->item.number, pt->item.grade);
			flag = 0;  //�ҵ����Ϊ0
		}
		else
			pt = pt->next;
	}
	if (flag)printf("No found��");
}

void ListInsertItem(List*plist)   //������Ϣ
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

void ListUpdate(const List*plist) //�޸�
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

void ListDeleteItem(List*plist)  //ɾ��
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

void show(const List *plist)  //���
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

void EmptyTheList(List*plist)  //�������
{
	List pt = *plist;
	while (*plist != NULL)
	{
		pt =(*plist)->next;
		free(*plist);
		*plist = pt;
	}
}