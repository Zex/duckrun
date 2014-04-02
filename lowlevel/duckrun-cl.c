#include <mysql.h>
#include <my_sys.h>

#include <stdio.h>
#include <string.h>

static MYSQL *db = 0;

void selftest()
{
	char req_str[] = "select * from duckinfo;";
	my_ulonglong col_nr = 0, row_nr = 0;
	my_ulonglong c, r;
	MYSQL_RES *res = 0;
	MYSQL_ROW row;

	mysql_real_query(db, req_str, strlen(req_str));
	res = mysql_store_result(db);

	printf("total fields: %llu\n", (col_nr=mysql_field_count(db)));
	printf("total rows: %llu\n", (row_nr=mysql_num_rows(res)));

	while (row_nr-- > 0) {
		if ((row = mysql_fetch_row(res))) {
			for (c = 0; c < col_nr;c++)
				printf("%s\t", row[c]);//*(row+c));
			printf("\n");
		}
	}
	mysql_free_result(res);
}

int main(void)
{
	char host[] = "localhost";
	char user[] = "duckadm";
	char passwd[] = "riskcud";
	char dbname[] = "duckrun";

	my_init();
	db = mysql_init(db);
	printf("default character set: %s\n", mysql_character_set_name(db));
	mysql_real_connect(db, host, user, passwd, dbname, 0, 0, 0);
	mysql_set_character_set(db, "utf8");
	printf("reset character set: %s\n", mysql_character_set_name(db));

	selftest();

	mysql_close(db);

	return 0;
}
