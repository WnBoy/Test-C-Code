#include<stdio.h>
#include "my_global.h"
#include"mysql.h"
#include"windows.h"
#include<stdlib.h>

void show();  //��ʾ����
void show_row();  //��ʾ��
void show_head();  //��ʾͷ��
void insert();   //��������
void update();  //��������
void delet();  //ɾ������
void menu();  //�˵�

MYSQL my_connection;
MYSQL_RES*res_ptr;
MYSQL_ROW sqlrow;
char query[100];
int main(int argc, char*argv[])
{
	int n;
	mysql_init(&my_connection);  //��ʼ�����ݿ�
	//�������ݿ�   localhost�Ǳ�����ַ��root���û�����1993�������ݿ����룬student-navicate test�����ݿ�����3306�Ƕ˿ں�
	if (!mysql_real_connect(&my_connection, "localhost", "root", "1993", "student-navicate test", 3306, NULL, 0))
	{
		fprintf(stderr, "Error connecting to datebase:%s", mysql_error(&my_connection));
	}
	else
		puts("Success connect...");
	//�����ַ�
	if (mysql_set_character_set(&my_connection, "gbk"))
	{
		fprintf(stderr, "����%s\n", mysql_error(&my_connection));
	}
	menu();  //�˵��б�  
	while (scanf("%d", &n) == 1)
	{
		while (getchar() != '\n')continue;
		switch (n)
		{
		case 1:show();break;  //��ʾ����
		case 2:insert();break;//��������
		case 3:delet();break;//ɾ��
		case 4:update();break;//����
		default:puts("Bye!");exit(1);//�˳�
		}
		menu();
	}
	mysql_close(&my_connection);//�ر����ݿ�
	getchar();
	return 0;
}
//��ʾ����
void show()
{
	int flag = 1;//���λ
	int res;
	res = mysql_query(&my_connection, "SELECT * FROM stu_info");
	if (res)
		fprintf(stderr, "SELECT error:%s\n", mysql_error(&my_connection));
	else
	{
		res_ptr = mysql_use_result(&my_connection);
		if (res_ptr)
		{
			if (flag)//��������У��������ͷ
			{
				show_head();
				flag = 0;//��־λ����
			}
			show_row();//�����������
		}
		else
		{
			puts("��ȡ���ݴ���!!!");
			fprintf(stderr, "Retrive error:%s\n", mysql_error(&my_connection));
		}
		mysql_free_result(res_ptr);  //��ջ���
	}
}
//��ʾ��ͷ
void show_head()
{
	MYSQL_FIELD *field_ptr;
	printf("Column details: \n");
	while ((field_ptr = mysql_fetch_field(res_ptr)) != NULL)
	{
		printf("\t Name: %s", field_ptr->name);
	}
	putchar('\n');
}
//��ʾ������
void show_row()
{
	unsigned int i, n;
	MYSQL_ROW sqlrow;
	n = mysql_num_fields(res_ptr);
	while ((sqlrow = mysql_fetch_row(res_ptr)))
	{
		for (i = 0;i < n;i++)
		{
			printf("%15s", sqlrow[i]);
		}
		putchar('\n');
	}
}

//��������
void insert()
{
	char id[20];
	char name[20];
	char sex[20];
	char address[20];
	char*find;
	puts("Please enter id,name,sex and address:");
	printf("Please enter id:");
	fgets(id, 20, stdin);
	find = strchr(id, '\n');
	if (find)*find = '\0';

	printf("Please enter neme:");
	fgets(name, 20, stdin);
	find = strchr(name, '\n');
	if (find)*find = '\0';

	printf("Please enter sex:");
	fgets(sex, 20, stdin);
	find = strchr(sex, '\n');
	if (find)*find = '\0';

	printf("Please enter address:");
	fgets(address, 20, stdin);
	find = strchr(address, '\n');
	if (find)*find = '\0';

	sprintf(query, "insert into stu_info(stu_id,stu_name,stu_sex,stu_address)value('%s','%s','%s','%s')",
		id, name, sex, address);
	if (mysql_query(&my_connection, query))
		fprintf(stderr, "���� is failure ,error is :%s", mysql_error(&my_connection));
	else
		puts("���� success!");
}
//��������
void update()
{
	char*find;
	char name[20];
	char id[20];
	puts("PLease enter you want to  update column and row");
	printf("Please enter column:");
	fgets(name, 20, stdin);
	find = strchr(name, '\n');
	if (find)*find = '\0';

	printf("Please enter id:");
	fgets(id, 20, stdin);
	find = strchr(id, '\n');
	if (find)*find = '\0';
	sprintf(query, "update stu_info set stu_name='%s',where id='%s'", name, id);
	if (mysql_query(&my_connection, query))
		fprintf(stderr, "��ѯ is failure ,error is :%s", mysql_error(&my_connection));
	else
		puts("��ѯ success!");
}
//ɾ������
void delet()
{
	char*find;
	char id[20];
	puts("Please enter id:");
	fgets(id, 20, stdin);
	find = strchr(id, '\n');
	if (find)*find = '\0';
	sprintf(query, "delete from stu_info where stu_id='%s'", id);
	if (mysql_query(&my_connection, query))
		fprintf(stderr, "ɾ�� is failure ,error is :%s", mysql_error(&my_connection));
	else
		puts("ɾ�� success!");
}
//�˵�
void menu()
{
	printf("\n\n\n\n\n\n");
	puts("\t\t|-------------ѧ��������ϵͳ------------|");
	puts("\t\t|\t 1.չʾ����.                    |");
	puts("\t\t|\t 2.��������.                    |");
	puts("\t\t|\t 3.ɾ����Ϣ.                    |");
	puts("\t\t|\t 4.��������.                    |");
	puts("\t\t|\t other number is quit.          |");
	puts("\t\t|---------------------------------------|");
	puts("\t\t\t\tchose(1-4):");
}