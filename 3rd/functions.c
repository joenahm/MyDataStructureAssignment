/*
	Author	: Joe Nahm
	Email	: joenahm@yeah.net
*/
#include "functions.h"

/* private functions */

/* private functions */

/* public functions */
void getInput(bt_elem_type *buffer){
	int temp = getchar();
	if( temp != ' ' ){
		buffer->data = temp - '0';
		buffer->isNull = FALSE;
	}else{
		buffer->isNull = TRUE;
	}
}

void visit(BTNode *nodep){
	printf("%d %c\n", getData(nodep->value),bt_isLeaf(*nodep)?'y':'n');
}
/* public functions */