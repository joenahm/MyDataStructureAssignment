/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
	Version	:	v0.1

	NOTICE:
	Define the 'elem_type' in 'sqlist_elem_type.h' before use !!
	The 'elem_type' defaultly is 'int'

	In this file "size" means memory space, and "length" means
	the length of the Squence List.
 */
#ifndef _SQLIST_H_
#define _SQLIST_H_

#include <stdlib.h>
#include <stdio.h>
#include "sqlist_elem_type.h"

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILURE 0

typedef struct SQLIST{
	elem_type *elem;
	int length;
	int size;
} SqList;

void sql_init(SqList *sql, int size);
int sql_getLen(SqList *sql);
int sql_getSize(SqList *sql);
int sql_isEmpty(SqList *sql);
int sql_isFull(SqList *sql);
elem_type sql_get(SqList *sql, int index);
void sql_insert(SqList *sql, int index, elem_type value);
int sql_grow(SqList *sql, int size);
void sql_destroy(SqList *sql);
/* remain to be done */

#endif