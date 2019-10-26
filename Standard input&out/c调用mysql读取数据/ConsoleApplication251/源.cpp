#include<stdio.h>
#include<windows.h>
#include"mysql.h"
#include <tchar.h> 

MYSQL my_connection;
MYSQL_RES*res_ptr;
MYSQL_ROW sqlrow;
void show_head();
int _tmain(int argc, _TCHAR*argv[])
{
	unsigned int n,i;
	int res;
	mysql_init(&my_connection);
	if (!mysql_real_connect(&my_connection, "localhost", "root", "1993", "student-navicate test", 3306, NULL, 0))
	{
		printf("Error connecting to datebase:%s", mysql_error(&my_connection));
	}
	else
		puts("success connect...");
	if (mysql_set_character_set(&my_connection, "gbk"))
	{
		fprintf(stderr, "´íÎó£¬%s\n", mysql_error(&my_connection));
	}
	res = mysql_query(&my_connection, "SELECT * FROM stu_info");
	if(res)
		fprintf(stderr,"SELECT error:%s\n",mysql_error(&my_connection));
	else
	{
		res_ptr = mysql_use_result(&my_connection);
		n = mysql_num_fields(res_ptr);
		printf("·µ»ØµÄ×Ö¶ÎÊý:%d\n", n);
		show_head();
			while ((sqlrow = mysql_fetch_row(res_ptr)))
			{
				for (i = 0;i < n;i++)
				{
					printf("%15s",sqlrow[i]);
				}
				putchar('\n');
			}
			if (mysql_errno(&my_connection))
			{
				fprintf(stderr, "Retrive error:%s\n", mysql_error(&my_connection));
			}
			mysql_free_result(res_ptr);		
	}
	mysql_close(&my_connection);
	getchar();
	return 0;
}

void show_head()
{
	MYSQL_FIELD *field_ptr;
	printf("Column details: \n");
	while ((field_ptr = mysql_fetch_field(res_ptr)) != NULL)
	{
		printf("\t  %s", field_ptr->name);
	}
	putchar('\n');
}