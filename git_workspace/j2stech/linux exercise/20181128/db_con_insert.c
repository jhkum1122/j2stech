#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int db_insert() {
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char *server = "localhost";
	char *user = "kum";
	char *password = "!@#qweasdzxc";
	char *database = "test";

	int row_ind, colum_ind = 0;

	if (!(conn = mysql_init((MYSQL *)NULL))) {
		perror("Init failed");
		return 0;
	}

	printf("Init Success\n%d\n", conn);

	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL,0)){
		perror("Init failed\n");
		return 0;
	}

	if (mysql_query(conn, "insert into ppp values(421, 'kkk')")){
		printf("Query failed, %d \n", mysql_query(conn, "insert into ppp"));
		return 0;
	}

	puts("Query Success");
	printf("\n");

	mysql_close(conn);

	return 0;
}


