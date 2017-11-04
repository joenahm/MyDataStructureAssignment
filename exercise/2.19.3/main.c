#include "header.h"

void sllist_delInterval(SLList sll, int minv, int maxv){
	register Node *prev = sll;
	register Node *current;
	while( (current=prev->next) != NULL ){
		if( current->value > minv
			&& current->value < maxv ){
			
			prev->next = current->next;
			free(current);
		}else{	
			prev = current;
		}
	}
}

int main(int argc, char const *argv[]){
	SLList sll1;
	sll_init(&sll1);

	int i;
	for( i = 0 ; i < 5 ; i ++ ){
		sll_insert(sll1,i);
	}

	sll_print(sll1);
	sllist_delInterval(sll1,1,4);
	sll_print(sll1);

	sll_destroy(sll1);

	return 0;
 }
