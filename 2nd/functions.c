#include "stack/stack.h"
#include "functions.h"
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_BUFF 100

int isoper(char value){/* operator check */
	int flag = TRUE;

	if( value!='+' && value!='-' && value!='*' && value!='/' && value!='(' && value!=')' && value!='=' )
		flag = FALSE;
	
	return flag;
}

double get_pow(double base,int power){/* exponentiation */
	double temp = 1.0;
	int i;

	if( power > 0 ){
		for( i = 0 ; i < power ; i++ )
			temp *= base;
	}else if( power < 0 ){
		for( i = 0 ; i < -power ; i++ )
			temp /= base;
	}

	return temp;
}

double get_number(char *buffer, int *buffer_index){/* number obtention */
	int power = 0;
	double temp =0.0;

	while( --(*buffer_index) >= 0 ){
		temp += (buffer[*buffer_index]-'0')*get_pow(10,power);
		power++;
	}

	*buffer_index = 0;

	return temp;
}

double calculate(double value1, char operator, double value2){/* binary calculation */
	double temp;

	switch( operator ){
		case '+':
			temp = value1 + value2;
			break;
		case '-':
			temp = value1 - value2;
			break;
		case '*':
			temp = value1 * value2;
			break;
		case '/':
			temp = value1 / value2;
			break;
		default:
			fprintf(stderr, "ERROR(calculate):unknown operator \"%c\" !\n", operator);
			exit(EXIT_FAILURE);
	}

	return temp;
}

char priority_comp(char op1, char op2){/* priority compare */
	char result;

	if( op2=='+' || op2=='-' ){
		if( op1=='(' || op1=='=' )
			result = '<';
		else
			result = '>';
	}else if( op2=='*' || op2=='/' ){
		if( op1=='*' || op1=='/' || op1==')' )
			result = '>';
		else
			result = '<';
	}else if( op2 == '(' ){
		if( op1==')' ){
			fprintf(stderr, "ERROR(priority_comp):invalid expression ! \n");
			exit(EXIT_FAILURE);
		}else
			result = '<';
	}else if( op2 == ')' ){
		if( op1 == '=' ){
			fprintf(stderr, "ERROR(priority_comp):invalid expression ! \n");
			exit(EXIT_FAILURE);
		}else if( op1 == '(' )
			result = '=';
		else
			result = '>';
	}else if( op2 == '=' ){
		if( op1=='(' || op1=='=' ){
			fprintf(stderr, "ERROR(priority_comp):invalid expression ! \n");
			exit(EXIT_FAILURE);
		}else
			result = '>';
	}else{
		fprintf(stderr, "ERROR(priority_comp):invalid expression ! \n");
		exit(EXIT_FAILURE);
	}

	return result;
}

void exp_eval(Stack *ops, Stack *nus){
	char in_val;
	char buffer[MAX_BUFF];	//a buffer for the transition from char to number
	int is_buffer_empty = TRUE;	//a flag to show the status of buffer
	int buffer_index = 0;	//storing the next available position of buffer

	while( (in_val=getchar()) != '\n' ){
		if( isdigit(in_val) ){	/* when input is a number */
			is_buffer_empty = FALSE;		//once buffer has been used,this flag turns to FALSE
			if( buffer_index < MAX_BUFF ){	//when buffer is not full
				buffer[buffer_index] = in_val;//store the input in the buffer
				buffer_index++;				//
			}
			else	/* when buffer is full */
				fprintf(stderr, "WARNING(exp_eval):buffer[MAX_BUFF] for number storing is full !\n");//warn, stop storing but exit not
		}else if( in_val == '.' ){	/* when input is a decimal */
			char dec_val;
			double number;	//to store the final result
			int power = 1;

			number = get_number(buffer,&buffer_index);	//get integer part
			is_buffer_empty = TRUE;		//buffer has cleaned because of get_number()

			while( (dec_val=getchar())>='0' && dec_val<='9' ){	//get decimal part
				number += (dec_val-'0')*get_pow(10,-power);	//add the decimal part to the integer part
				power++;
			}
			ungetc(dec_val,stdin);	//send the non-number input back

			stack_push(nus,number);	//push the result into stack
		}else if( isoper(in_val) ){	/* when input is an operator */
			double number2;
			if( !is_buffer_empty )	/* prepare number2 */
				number2 = get_number(buffer,&buffer_index);//get the number directly when it has not been pushed in stack
			else
				number2 = stack_getTop(nus);	//get a number from the Top of stack

			if(stack_isEmpty(ops)){	//when operator_stack is empty
				stack_push(ops,in_val); //push the input into stack directly

				if( !is_buffer_empty )	//if gotten that number
					stack_push(nus,number2); //push it into number_stack
			}else{	//when operator_stack is not empty
				switch( priority_comp((char)stack_getTop(ops),in_val) ){//do the priority compare between the Top of operator_stack and the input
					case '<':
						stack_push(ops,in_val);//when < , push it into stack
						if( !is_buffer_empty )	//store the number2
							stack_push(nus,number2);//
						break;
					case '=':
						stack_pop(ops);//when = , they must be "(" and ")", so ignore them
						if( !is_buffer_empty )	//store the number2
							stack_push(nus,number2);
						break;
					case '>':
					{
						if( is_buffer_empty )//when > , time for calculation.when number2 is from stack
							stack_pop(nus);	//pop it out

						double number1 = stack_getTop(nus);	//prepare number1 from stack
						stack_pop(nus);	//then pop it out

						stack_push(nus,calculate(number1,(char)stack_getTop(ops),number2));//do the calculation
						stack_pop(ops);//pop the operator that just be used out
						
						if( in_val!='=' && in_val!=')' )//when it is a operator for future calculation
							stack_push(ops,in_val);//push it into stack
						else
							ungetc(in_val,stdin);//when it is a controller, send it back to input
					}
				}
			}
			
			is_buffer_empty = TRUE; //when buffer has experienced "is-operator-branch", it must has been cleaned
		}else{	/* when input is invalid */
			fprintf(stderr, "ERROR(exp_eval):invalid input \"%c\" !\n", in_val);
			exit(EXIT_FAILURE);
		}
	}	

	if( (char)stack_getTop(ops) != '=' ){	/* when expression is invalid */
		fprintf(stderr, "ERROR(exp_eval):expression must end with \"=\" ! \n");
		exit(EXIT_FAILURE);
	}
}