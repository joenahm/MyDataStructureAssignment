#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
/*
	Expression Evaluation
	Input:
		Stack *operator_stack
		Stack *number_stack
	Output:
		Stack *number_stack
	Implementation:
		Get expression from user input, process the expression with these 2 stacks.
		Then you will get the result in the Top of number_stack.

	Note:
		1. + - * / () are available, negative number is unavailable !
		2. The expression must end with a '=' !
*/
void exp_eval(Stack *operator_stack, Stack *number_stack);

#endif