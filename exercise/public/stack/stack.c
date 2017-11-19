/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
 */

#include "stack.h"
#include <assert.h>

void stack_init(Stack *stackp){
	stackp->size = 0;
}

int stack_isEmpty(Stack *stackp){
	return !stackp->size;
}

int stack_isFull(Stack *stackp){
	return stackp->size == MAX_SIZE;
}

elem_type stack_getTop(Stack *stackp){
	assert(!stack_isEmpty(stackp));

	return stackp->data[stackp->size-1];
}

void stack_pop(Stack *stackp){
	assert(!stack_isEmpty(stackp));

	stackp->size--;
}

void stack_push(Stack *stackp, elem_type value){
	assert(!stack_isFull(stackp));

	stackp->data[stackp->size] = value;
	stackp->size++;
}
