#include "header.h"

SLList sllist_freeHeadNode(SLList sll){
	Node *headNode = sll;
	sll = sll->next;
	free(headNode);

	return sll;
}

void sllist_decreInsert(Node **headerp, Node* node){
	Node *current = *headerp;
	Node **linkp = headerp;

	while( current != NULL
		&& node->value < current->value ){

		linkp = &(current->next);
		current = current->next;
	}

	/* 	when "while" hasn't worked, *linkp is the "header"; 
	*	when it has worked, *linkp is exactly the position to insert.
	*/
	*linkp = node;	
	node->next = current;
}

Node* sllist_2increTo1decre(SLList sll1, SLList sll2){
	sll1 = sllist_freeHeadNode(sll1);
	sll2 = sllist_freeHeadNode(sll2);

	Node *header = NULL;
	while( sll1 != NULL || sll2 != NULL ){
		if( sll1 != NULL ){
			Node *temp1 = sll1;
			sll1 = sll1->next;

			sllist_decreInsert(&header,temp1);
		}

		if( sll2 != NULL ){
			Node *temp2 = sll2;
			sll2 = sll2->next;

			sllist_decreInsert(&header,temp2);
		}
	}

	return header;
}

int main(int argc, char const *argv[]){
	SLList sll1,sll2,sll3;
	sll_init(&sll1);
	sll_init(&sll2);
	sll_init(&sll3);

	int i;
	for( i = 1 ; i <= 4 ; i++ ){
		sll_insert(sll1,i);
	}
	sll_insert(sll2,3);
	sll_insert(sll2,5);
	sll_insert(sll2,5);
	sll_insert(sll2,8);
	sll_insert(sll2,8);

	sll_print(sll1);
	sll_print(sll2);

	sll3->next = sllist_2increTo1decre(sll1,sll2);

	sll_print(sll3);

	sll_destroy(sll3);

	return 0;
 }
