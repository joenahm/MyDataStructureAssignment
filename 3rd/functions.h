/*
	Author	: Joe Nahm
	Email	: joenahm@yeah.net
*/
#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
#include "binary-tree/bt_elem_type.h"

#define TRUE 1
#define FALSE 0

void getInput(bt_elem_type *buffer);
void visit(BTNode *node);

#endif