// cgi_select.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<stdio.h>
#include <Windows.h>
#include <mysql.h>
#pragma comment(lib,"libmysql.lib")

MYSQL mysql;
MYSQL_RES* result;
MYSQL_ROW row;

void main()
{
	MYSQL mysql, *sock;
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql, "localhost", "root", "1993", "test", 3306, NULL, 0)))
	{
		printf("Cannot connect to database:%s\n", mysql_error(sock));
		return;
	}

	char sqlbuf[200] = "SELECT * FROM data";
	if (mysql_query(sock, sqlbuf))
	{
		printf("Query Failed:%s", mysql_error(sock));
		return;
	}

	MYSQL_RES *result;
	unsigned uLine = 0, uField = 0;
	MYSQL_ROW row;
	//MYSQL_FIELD **pField;pField = NULL;  
	MYSQL_FIELD *pField(NULL);
	unsigned long *lengths;

	if (!(result = mysql_store_result(sock)))
	{
		printf("Failed to store result:%s", mysql_error(sock));
		return;
	}

	//获得行数  
	uLine = (unsigned)mysql_num_rows(result);
	//获得字段数  
	uField = (unsigned)mysql_num_fields(result);
	//获得字段的相关信息  
	//for(int j = 0; j < (int)uField; ++j)  
	//{  
	//  pField[j] =mysql_fetch_field_direct(result, j);  
	//}  
	pField = mysql_fetch_fields(result);

	//填充结果集  
	for (int i = 0; i<(int)uLine; i++)
	{
		//获得一行数据  
		row = mysql_fetch_row(result);
		lengths = mysql_fetch_lengths(result);
		for (int j = 0; j<(int)uField; j++)
		{
			//blob  
			MYSQL_FIELD *pTemp = pField + j;
			if (pTemp->type == MYSQL_TYPE_BLOB)
			{
				//列名称  
				printf("%s:%d--%d ", pTemp->name, lengths[j], pTemp->max_length);
				for (unsigned long nindex = 0; nindex < lengths[j]; ++nindex)
				{
					printf("%02X", row[j][nindex]);
				}
			}
			else
			{
				//列名称  
				printf("%s:%d--%d %s", pTemp->name, lengths[j], pTemp->max_length, row[j]);
			}
			printf("\t");
		}
		printf("\n");
	}
	//if(pField) delete []pField;  

	//释放结果集  
	mysql_free_result(result);

	// 关闭数据库  
	mysql_close(sock);
}