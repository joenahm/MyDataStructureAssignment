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
	printf("%-6s : %d\n", tbt_isLeaf(*nodep)?"Leaf":"Branch", getData(nodep->value));
}
/* public functions */