#include "header.h"

int sqlist_Cmp(SqList *sql1, SqList *sql2){
	int i = 0;
	while( sql_get(sql1,i) == sql_get(sql2,i)
		&& i < sql_getLen(sql1)
		&& i < sql_getLen(sql2) ){

		i++;
	}

	int result;
	if( i == sql_getLen(sql1)
		&& i == sql_getLen(sql2) ){

		result = 0;
	}else if( (i==sql_getLen(sql1)&&i!=sql_getLen(sql2))
			|| (i!=sql_getLen(sql1)&&i!=sql_getLen(sql2)&&sql_get(sql1,i)<sql_get(sql2,i)) ){

		result = -1;
	}else{
		result = 1;
	}

	return result;
}

int main(int argc, char const *argv[]){
	SqList sql1,sql2;
	sql_init(&sql1,10);
	sql_init(&sql2,10);

	int i;
	for( i = 0 ; i < 5 ; i++ ){
		sql_insert(&sql1,i,i);
		sql_insert(&sql2,i,i);
	}

	for( i = 5 ; i < 10 ; i++ ){
		sql_insert(&sql2,i,i);
	}
	
	printf("sql1:");
	sql_print(&sql1,sql_getLen(&sql1));
	printf("sql2:");
	sql_print(&sql2,sql_getLen(&sql2));

	int result = sqlist_Cmp(&sql1,&sql2);
	char oper;
	switch( result ){
		case -1:
			oper = '<';
			break;
		case 0:
			oper = '=';
			break;
		case 1:
			oper = '>';
			break;
	}
	printf("result: sql1 %c sql2\n", oper);

	sql_destroy(&sql1);
	sql_destroy(&sql2);

	return 0;
 }
