/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
	Version	:	v0.2

	NOTICE:
	Define the 'elem_type' in 'sllist_elem_type.h' before use !!
	The 'elem_type' defaultly is 'int'
 */
#ifndef _LLIST_H_
#define _LLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "sllist_elem_type.h"

typedef struct NODE{
	elem_type value;
	struct NODE *next;
} Node,*SLList;

void sll_init(SLList *sll_headpp);
void sll_insert(SLList sll, elem_type new_value);
void sll_print(SLList sll);
void sll_destroy(SLList sll);

#endif