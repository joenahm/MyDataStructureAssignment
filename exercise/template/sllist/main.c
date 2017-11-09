#include "header.h"

int main(int argc, char const *argv[]){
	SLList sll1;
	sll_init(sll1);
	sll_insert(sll1,1);
	printf("%d\n", sll1->value);
	sll_destroy(sll1);

	return 0;
 }
