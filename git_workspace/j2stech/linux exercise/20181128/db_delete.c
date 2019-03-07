#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main() {
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

	if (mysql_query(conn, "delete from ppp where user_no=421")) {
		printf("Query failed, %d \n", mysql_query(conn, "delete from ppp"));
		return 0;
	}

	puts("Query Success");
/*
//	res = mysql_store_result(conn);			//kjh error

	printf("RES's fields : %d , rows : %d\n",mysql_num_fields(res), mysql_num_rows(res)); 
	puts("RES Success");

	printf("RES's fields : %d , rows : %d\n",mysql_num_fields(res), mysql_num_rows(res)); 
*/
/*
//kjh for-for
	row = mysql_fetch_row(res);

	for(row_ind = mysql_num_rows(res); row_ind < 1; row_ind--) 
		for(colum_ind = mysql_num_fields(res); colum_ind < 1; colum_ind--) 
			printf("%s", row[colum_ind]);
*/

//kjh error
/*
	while((row = mysql_fetch_row(res)) != NULL)
		printf("%s %s", row[0], row[1]);
*/
	printf("\n");

	mysql_close(conn);

	return 0;
}


