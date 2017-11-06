/*
	Author	: Joe Nahm
	Email	: joenahm@yeah.net
*/
#include "binary-tree/bt.h"
#include "functions.h"

int main(int argc, char const *argv[]){
	BT bt;
	bt_init(&bt);
	bt_create(&bt);	
	bt_inOrderTraverse(bt,&visit);

	return 0;
}