/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
	Version	:	v0.1

	NOTICE:
	Define the 'tbt_elem_type' in 'tbt_elem_type.h' before use !!
	The 'tbt_elem_type' defaultly is 'int'
 */
#ifndef _TBT_H_
#define _TBT_H_

#include <stdio.h>
#include <stdlib.h>
#include "tbt_elem_type.h"
#include "../stack/stack.h"

#define TRUE 1
#define FALSE 0
#define NODE 1
#define THREAD 0

void tbt_init(TBT *rootpp);
void tbt_create(TBT *rootpp); 
void tbt_preOrderTraverse(TBT rootp, void (*visit)(TBTNode *nodep));
void tbt_inOrderTraverse(TBT rootp, void (*visit)(TBTNode *nodep));
void tbt_postOrderTraverse(TBT rootp, void (*visit)(TBTNode *nodep));
void tbt_inOrderThreading(TBT rootp, Stack *nodes);
void tbt_destroy(TBT tree);

int getData(tbt_elem_type value);

#endif