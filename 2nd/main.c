#include "stack/stack.h"
#include "functions.h"

int main(int argc, const char *argv[]){
	Stack operator;
	Stack number;
	stack_init(&operator);
	stack_init(&number);

	exp_eval(&operator,&number);

	printf("%f\n", stack_getTop(&number));

	return 0;
}