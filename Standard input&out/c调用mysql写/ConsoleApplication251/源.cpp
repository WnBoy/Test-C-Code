#include<stdio.h>
#include<windows.h>
#include"mysql.h"
#include <tchar.h> 
//#pragma comment(lib,"libmysql.lib")
int _tmain(int argc,_TCHAR*argv[])
{
	char*find;
	MYSQL mysql;
	MYSQL_RES*res;
	MYSQL_ROW row;
	char*query;
	char input[100];
	char name[20];
	int t, r;
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "1993", "student-navicate test", 3306, NULL, 0))
	{
		printf("Error connecting to datebase:%s", mysql_error(&mysql));
	}
	else puts("success connect...");
	query = "SET CHARACTER SET gbk";
	t = mysql_real_query(&mysql, query, (unsigned int)strlen(query));
	if (t)printf("����ʧ�ܣ�");
	printf("Please enter neme:");
	fgets(name, 50, stdin);
	find = strchr(name, '\n');
	if (find)*find = '\0';
	sprintf(input, "insert into stu_info(stu_id,stu_name,stu_sex,stu_address)values(121501,'%s','w','xy')",name);
	t = mysql_query(&mysql, input);
	if (t)
		printf("ִ��mysql���ʱ�����쳣:%s", mysql_error(&mysql));
	else
		printf("[%s]�����ɹ�\n", query);
	mysql_close(&mysql);
	getchar();
	return 0;
}