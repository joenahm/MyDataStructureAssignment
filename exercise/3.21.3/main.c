#include "header.h"

#define OPER 1
#define VAR 0
#define HIGH 1
#define LOW 0

int typeCheck(char val){
	int status;
	if( val >= 'a' && val <= 'z' ){
		status = VAR;
	}else{
		status = OPER;
	}

	return status;
}

int priorityCheck(char val){
	int status;
	if( val == '*' || val == '/' ){
		status = HIGH;
	}else{
		status = LOW;
	}

	return status;
}

/* 
*	NOTICE:
*	The expStr must be a char array.
*	For example: char *s = "a+b";
*	You cannot put variable 's' into the function toRNP() !
*/
void toRPN(char *expStr){
	Stack lowOperStack;
	stack_init(&lowOperStack);

	int i = 0;
	int avaiIndex = 0;
	char current;
	while( (current=expStr[i]) != '\0' ){
		switch( typeCheck(current) ){
			case VAR:
				expStr[avaiIndex] = current;
				avaiIndex++;
			break;
			case OPER:
				if( priorityCheck(current) == LOW ){
					stack_push(&lowOperStack,current);
				}else{
					i++;
					expStr[avaiIndex] = expStr[i];
					expStr[avaiIndex+1] = current;
					avaiIndex += 2;
				}
			break;
		}

		i++;
	}

	while( !stack_isEmpty(&lowOperStack) ){
		expStr[avaiIndex] = stack_getTop(&lowOperStack);
		stack_pop(&lowOperStack);
		
		avaiIndex++;
	}
}

int main(int argc, char const *argv[]){
	char str[] = "a+b*c/d-e";
	toRPN(str);
	puts(str);

	return 0;
}
