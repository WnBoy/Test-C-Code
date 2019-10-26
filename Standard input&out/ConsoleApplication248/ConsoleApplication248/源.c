#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql.h"
#include "errmsg.h"
#include "mysqld_error.h"

MYSQL conn;
MYSQL_RES *res_ptr;
MYSQL_ROW sqlrow;

void connection(const char* host, const char* user, const char* password, const char* database) {
	mysql_init(&conn); // ×¢ÒâÈ¡µØÖ··û&

	if (mysql_real_connect(&conn,"localhost", "root", "1993", "test", 3306, NULL, 0)) {
		printf("Connection success!\n");
	}
	else {
		fprintf(stderr, "Connection failed!\n");
		if (mysql_errno(&conn)) {
			fprintf(stderr, "Connection error %d: %s\n", mysql_errno(&conn), mysql_error(&conn));
		}
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[]) {

	connection("localhost", "root", "shuang", "shuangde");
	int res = mysql_query(&conn, "SELECT * from student");
	if (res) {
		fprintf(stderr, "SELECT error: %s\n", mysql_error(&conn));
	}
	else {
		res_ptr = mysql_store_result(&conn);
		if (res_ptr) {
			printf("Retrieved %lu rows\n", (unsigned long)mysql_num_rows(res_ptr));
			while ((sqlrow = mysql_fetch_row(res_ptr))) {
				printf("Fetched data...\n");
			}
			if (mysql_errno(&conn)) {
				fprintf(stderr, "Retrive error: %s\n", mysql_error(&conn));
			}
			mysql_free_result(res_ptr);
		}
	}
	mysql_close(&conn);
	exit(EXIT_SUCCESS);
}