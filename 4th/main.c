/*
	Author	: Joe Nahm
	Email	: joenahm@yeah.net
*/
#include "digraph/dg.h"

int main(int argc, char const *argv[]){
	ALGraph dg1;
	alg_init(&dg1);
	alg_create(&dg1);
	alg_BFSTraverse(&dg1,&visitPrint);

	return 0;
}