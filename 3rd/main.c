/*
	Author	: Joe Nahm
	Email	: joenahm@yeah.net
*/
#include "binary-tree/tbt.h"
#include "functions.h"

int main(int argc, char const *argv[]){
	TBT bt;
	tbt_init(&bt);
	tbt_create(&bt);	
	Stack nodes;
	stack_init(&nodes);
	tbt_inOrderThreading(bt,&nodes);
	tbt_inOrderTraverse(bt,&visit);
	tbt_destroy(bt);

	return 0;
}