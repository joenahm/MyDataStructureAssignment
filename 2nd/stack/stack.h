/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
	Version	:	v0.1

	NOTICE:
	Define the 'elem_type' in 'stack_elem_type.h' before use !!
	The 'elem_type' defaultly is 'int'

	The storage mode of stack decides on head file 'stack_storage.h'
	And there is a struct called 'Stack' out there. It has 2 elements(data,size)
	whatever the storage mode is. 
	So the operations of stack has nothing to do with its storage mode.

	The default storage mode is 'static-mode', which means "the stack is
	based on static Array", and the length of this Array is 100.
	If you want something different, check and modify that file.
 */
#ifndef _STACK_H_

#include "stack_elem_type.h"
#include "stack_storage.h"
	
void stack_init(Stack *stackp);
int stack_isEmpty(Stack *stackp);
int stack_isFull(Stack *stackp);
elem_type stack_getTop(Stack *stackp);
void stack_pop(Stack *stackp);
void stack_push(Stack *stackp, elem_type value);

#endif