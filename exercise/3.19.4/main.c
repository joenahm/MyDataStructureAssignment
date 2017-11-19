#include "header.h"

#define TRUE 1
#define FALSE 0

int match(Stack *stack, char key){
	int status;
	if( stack_getTop(stack) != key ){
		status = FALSE;
	}else{
		status = TRUE;
		stack_pop(stack);
	}

	return status;
}

int bracketsMatch(char const *str){
	int status = TRUE;
	Stack stack;
	stack_init(&stack);

	int i = 0;
	while( str[i] != '\0' && status ){
		switch( str[i] ){
			case '(':
			case '[':
			case '{':
				stack_push(&stack,str[i]);
				break;
			case ')':
				status = match(&stack,'(');
				break;
			case ']':
				status = match(&stack,'[');
				break;
			case '}':
				status = match(&stack,'{');
				break;
		}

		i++;
	}

	if( str[i] == '\0' 
	&& (str[i-1]=='('||str[i-1]=='['||str[i-1]=='{') ){

		status = FALSE;
	}

	return status;
}

int main(int argc, char const *argv[]){
	char *str = "(int argc, char const *argv[])";
	printf("%d\n", bracketsMatch(str));

	return 0;
 }
