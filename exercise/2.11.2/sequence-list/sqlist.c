/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
 */
#include "sqlist.h"
#include <assert.h>

void sql_init(SqList *sql, int size){
	sql->elem = (elem_type*)malloc(sizeof(elem_type)*size);	
	if( sql->elem != NULL ){
		sql->size = size;
		sql->length = 0;
	}else{
		fprintf(stderr, "ERROR(sqlist_init):faild to init SqList !\n");
		exit(EXIT_FAILURE);
	}
}

int sql_getLen(SqList *sql){
	return sql->length;
}

void sql_setLen(SqList *sql, int newLength){
	sql->length = newLength;
}

int sql_getSize(SqList *sql){
	return sql->size;
}

int sql_isEmpty(SqList *sql){
	int status;
	if( sql->length == 0 ){
		status = TRUE;
	}else{
		status = FALSE;
	}

	return status;
}

int sql_isFull(SqList *sql){
	int status;
	if( sql->length == sql->size ){
		status = TRUE;
	}else{
		status = FALSE;
	}

	return status;
}

elem_type sql_get(SqList *sql, int index){
	assert(!sql_isEmpty(sql));

	return sql->elem[index];
}

void sql_set(SqList *sql, int index, elem_type value){
	assert(!sql_isFull(sql));

	sql->elem[index] = value;
}

void sql_insert(SqList *sql, int index, elem_type value){
	sql_set(sql,index,value);
	sql->length++;
}

int sql_grow(SqList *sql, int size){
	elem_type *temp;
	int status;
	temp = (elem_type*)realloc(sql->elem,sizeof(elem_type)*size);
	if( temp != NULL ){
		sql->elem = temp;
		sql->size += size;

		status = SUCCESS;
	}else{
		fprintf(stderr, "WARNING(sqlist_grow):faild to grow SqList !\n");
		status = FAILURE;
	}

	return status;
}

void sql_destroy(SqList *sql){
	free(sql->elem);
}