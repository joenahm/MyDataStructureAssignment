/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
	Version	:	v0.1

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

void sll_init(SLList *sll_headp);
void sll_insert(SLList *sll, elem_type new_value);
void sll_destroy(SLList sll_headp);

#endif