#include "header.h"

int main(int argc, char const *argv[]){
	Stack stack;
	stack_init(&stack);
	stack_push(&stack,10);
	stack_push(&stack,11);
	printf("%d\n", stack_getTop(&stack));
	stack_pop(&stack);
	printf("%d\n", stack_getTop(&stack));

	return 0;
 }
