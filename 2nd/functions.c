#include "stack/stack.h"
#include "functions.h"
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_BUFF 100

int isoper(char value){
	int flag = TRUE;

	if( value!='+' && value!='-' && value!='*' && value!='/' && value!='(' && value!=')' && value!='=' )
		flag = FALSE;
	
	return flag;
}

double get_pow(double base,int power){
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

double get_number(char *buffer, int *buffer_index){
	int power = 0;
	double temp =0.0;

	while( --(*buffer_index) >= 0 ){
		temp += (buffer[*buffer_index]-'0')*get_pow(10,power);
		power++;
	}

	*buffer_index = 0;

	return temp;
}

double calculate(double value1, char operator, double value2){
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

char prority_comp(char op1, char op2){
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
			fprintf(stderr, "ERROR(prority_comp):invalid expression ! \n");
			exit(EXIT_FAILURE);
		}else
			result = '<';
	}else if( op2 == ')' ){
		if( op1 == '=' ){
			fprintf(stderr, "ERROR(prority_comp):invalid expression ! \n");
			exit(EXIT_FAILURE);
		}else if( op1 == '(' )
			result = '=';
		else
			result = '>';
	}else if( op2 == '=' ){
		if( op1=='(' || op1=='=' ){
			fprintf(stderr, "ERROR(prority_comp):invalid expression ! \n");
			exit(EXIT_FAILURE);
		}else
			result = '>';
	}else{
		fprintf(stderr, "ERROR(prority_comp):invalid expression ! \n");
		exit(EXIT_FAILURE);
	}

	return result;
}

void exp_eval(Stack *ops, Stack *nus){
	char in_val;
	char buffer[MAX_BUFF];
	int is_buffer_empty = TRUE;
	int buffer_index = 0;

	// stack_push(nus,0.0);

	while( (in_val=getchar()) != '\n' ){
		if( isdigit(in_val) ){
			is_buffer_empty = FALSE;
			if( buffer_index < MAX_BUFF ){
				buffer[buffer_index] = in_val;
				buffer_index++;
			}
			else
				fprintf(stderr, "WARNING(exp_eval):buffer[MAX_BUFF] for number storing is full !\n");
		}else if( in_val == '.' ){
			char dec_val;
			double number;
			int power = 1;

			number = get_number(buffer,&buffer_index);
			is_buffer_empty = TRUE;

			while( (dec_val=getchar())>='0' && dec_val<='9' ){
				number += (dec_val-'0')*get_pow(10,-power);
				power++;
			}
			ungetc(dec_val,stdin);

			stack_push(nus,number);
		}else if( isoper(in_val) ){
			double number2;
			if( !is_buffer_empty )
				number2 = get_number(buffer,&buffer_index);
			else
				number2 = stack_getTop(nus);

			if(stack_isEmpty(ops)){
				stack_push(ops,in_val);

				if( !is_buffer_empty )
					stack_push(nus,number2);
			}else{
				switch( prority_comp((char)stack_getTop(ops),in_val) ){
					case '<':
						stack_push(ops,in_val);
						if( !is_buffer_empty )
							stack_push(nus,number2);
						break;
					case '=':
						stack_pop(ops);
						if( !is_buffer_empty )
							stack_push(nus,number2);
						break;
					case '>':
					{
						if( is_buffer_empty )
							stack_pop(nus);

						double number1 = stack_getTop(nus);
						stack_pop(nus);

						stack_push(nus,calculate(number1,(char)stack_getTop(ops),number2));
						stack_pop(ops);
						
						if( in_val!='=' && in_val!=')' )
							stack_push(ops,in_val);
						else
							ungetc(in_val,stdin);
					}
				}
			}
			
			is_buffer_empty = TRUE;
		}else{
			fprintf(stderr, "ERROR(exp_eval):invalid input \"%c\" !\n", in_val);
			exit(EXIT_FAILURE);
		}
	}	
}