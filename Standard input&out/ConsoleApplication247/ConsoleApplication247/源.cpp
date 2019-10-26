// cgi_select.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//�������  
	uLine = (unsigned)mysql_num_rows(result);
	//����ֶ���  
	uField = (unsigned)mysql_num_fields(result);
	//����ֶε������Ϣ  
	//for(int j = 0; j < (int)uField; ++j)  
	//{  
	//  pField[j] =mysql_fetch_field_direct(result, j);  
	//}  
	pField = mysql_fetch_fields(result);

	//�������  
	for (int i = 0; i<(int)uLine; i++)
	{
		//���һ������  
		row = mysql_fetch_row(result);
		lengths = mysql_fetch_lengths(result);
		for (int j = 0; j<(int)uField; j++)
		{
			//blob  
			MYSQL_FIELD *pTemp = pField + j;
			if (pTemp->type == MYSQL_TYPE_BLOB)
			{
				//������  
				printf("%s:%d--%d ", pTemp->name, lengths[j], pTemp->max_length);
				for (unsigned long nindex = 0; nindex < lengths[j]; ++nindex)
				{
					printf("%02X", row[j][nindex]);
				}
			}
			else
			{
				//������  
				printf("%s:%d--%d %s", pTemp->name, lengths[j], pTemp->max_length, row[j]);
			}
			printf("\t");
		}
		printf("\n");
	}
	//if(pField) delete []pField;  

	//�ͷŽ����  
	mysql_free_result(result);

	// �ر����ݿ�  
	mysql_close(sock);
}