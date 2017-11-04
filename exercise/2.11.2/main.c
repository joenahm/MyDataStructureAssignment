#include "header.h"

typedef int Status;
#define SUCCESS 1
#define FAILURE 0

Status sqlist_autoInsert(SqList *sql,int value){// insert data into an increment sqlist
	/* get the postion where the "value" should be */
	int thePos = 0;
	while( thePos < sql_getLen(sql)
		&& sql_get(sql,thePos) < value ){

		thePos++;
	}

	/* move the existed data to prepare position for the "value" */
	int nextPosToMov = sql_getLen(sql) -1;
	int nextAvaiPos = nextPosToMov + 1;
	while( nextAvaiPos < sql_getSize(sql)
		&& nextPosToMov >= thePos ){

		sql_set(sql,nextAvaiPos,sql_get(sql,nextPosToMov));
		nextPosToMov--;
		nextAvaiPos = nextPosToMov + 1;
	}

	/* write the "value" */
	Status status;
	if( nextAvaiPos >= sql_getSize(sql) ){
		fprintf(stderr, "WARNING(sqlist_autoInsert): lack of space !\n");
		status = FAILURE;
	}else{
		sql_set(sql,thePos,value);
		sql_setLen(sql,sql_getLen(sql)+1);

		status = SUCCESS;
	}

	return status;
}

int main(int argc, char const *argv[]){
	int i;
	SqList sql1;
	sql_init(&sql1,10);

	for( i=0 ; i<sql_getSize(&sql1)-1 ; i++ ){
		sql_insert(&sql1,i,i);
	}

	Status status = sqlist_autoInsert(&sql1,2);

	if( status ){
		for( i=0 ; i<sql_getLen(&sql1) ; i++ ){
			printf("%d\n", sql_get(&sql1,i));
		}
	}else{
		fprintf(stderr, "WARNING(main): failed to auto-insert !\n");
	}

	sql_destroy(&sql1);

	return 0;
 }