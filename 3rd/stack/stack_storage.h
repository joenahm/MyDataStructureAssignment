/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
 */
#ifndef _STACK_STORAGE_H_
#define _STACK_STORAGE_H_

#include "stack_elem_type.h"

/* static-mode */
#define MAX_SIZE 100
typedef struct{
	elem_type data[MAX_SIZE];
	int size;	
} Stack;

#endif