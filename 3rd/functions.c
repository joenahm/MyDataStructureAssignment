/*
	Author	: Joe Nahm
	Email	: joenahm@yeah.net
*/
#include "functions.h"

/* private functions */

/* private functions */

/* public functions */
void getInput(tbt_elem_type *buffer){
	int temp = getchar();
	if( temp != ' ' ){
		buffer->data = temp - '0';
		buffer->isNull = FALSE;
	}else{
		buffer->isNull = TRUE;
	}
}

void visit(TBTNode *nodep){
	printf("%d\n", getData(nodep->value));
	fflush(stdout);
}
/* public functions */