#include "stack/stack.h"
#include "functions.h"

#define MAX_STR 100

int main(int argc, const char *argv[]){
	Stack operator;
	Stack number;
	stack_init(&operator);
	stack_init(&number);

	exp_calc(&operator,&number);

	return 0;
}