#include<stdio.h>
#include "my_global.h"
#include"mysql.h"
#include"windows.h"
#include<stdlib.h>

void show();  //显示函数
void show_row();  //显示行
void show_head();  //显示头行
void insert();   //插入数据
void update();  //更新数据
void delet();  //删除数据
void menu();  //菜单

MYSQL my_connection;
MYSQL_RES*res_ptr;
MYSQL_ROW sqlrow;
char query[100];
int main(int argc, char*argv[])
{
	int n;
	mysql_init(&my_connection);  //初始化数据库
	//连接数据库   localhost是本机地址，root是用户名，1993是我数据库密码，student-navicate test是数据库名，3306是端口号
	if (!mysql_real_connect(&my_connection, "localhost", "root", "1993", "student-navicate test", 3306, NULL, 0))
	{
		fprintf(stderr, "Error connecting to datebase:%s", mysql_error(&my_connection));
	}
	else
		puts("Success connect...");
	//设置字符
	if (mysql_set_character_set(&my_connection, "gbk"))
	{
		fprintf(stderr, "错误，%s\n", mysql_error(&my_connection));
	}
	menu();  //菜单列表  
	while (scanf("%d", &n) == 1)
	{
		while (getchar() != '\n')continue;
		switch (n)
		{
		case 1:show();break;  //显示数据
		case 2:insert();break;//插入数据
		case 3:delet();break;//删除
		case 4:update();break;//更新
		default:puts("Bye!");exit(1);//退出
		}
		menu();
	}
	mysql_close(&my_connection);//关闭数据库
	getchar();
	return 0;
}
//显示函数
void show()
{
	int flag = 1;//标记位
	int res;
	res = mysql_query(&my_connection, "SELECT * FROM stu_info");
	if (res)
		fprintf(stderr, "SELECT error:%s\n", mysql_error(&my_connection));
	else
	{
		res_ptr = mysql_use_result(&my_connection);
		if (res_ptr)
		{
			if (flag)//如果是首行，则输出表头
			{
				show_head();
				flag = 0;//标志位归零
			}
			show_row();//输出表中内容
		}
		else
		{
			puts("获取数据错误!!!");
			fprintf(stderr, "Retrive error:%s\n", mysql_error(&my_connection));
		}
		mysql_free_result(res_ptr);  //清空缓存
	}
}
//显示表头
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
//显示表内容
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

//插入数据
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
		fprintf(stderr, "插入 is failure ,error is :%s", mysql_error(&my_connection));
	else
		puts("插入 success!");
}
//更新数据
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
		fprintf(stderr, "查询 is failure ,error is :%s", mysql_error(&my_connection));
	else
		puts("查询 success!");
}
//删除数据
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
		fprintf(stderr, "删除 is failure ,error is :%s", mysql_error(&my_connection));
	else
		puts("删除 success!");
}
//菜单
void menu()
{
	printf("\n\n\n\n\n\n");
	puts("\t\t|-------------学生管理里系统------------|");
	puts("\t\t|\t 1.展示数据.                    |");
	puts("\t\t|\t 2.插入数据.                    |");
	puts("\t\t|\t 3.删除信息.                    |");
	puts("\t\t|\t 4.更新数据.                    |");
	puts("\t\t|\t other number is quit.          |");
	puts("\t\t|---------------------------------------|");
	puts("\t\t\t\tchose(1-4):");
}