/* 
	Author	:	Joe Nahm
	Emial	:	joenahm@yeah.net
 */
#include "sllist.h"

void sll_init(SLList *sll_headp){
	*sll_headp = NULL;
}

void sll_insert(Node **nextp, elem_type new_value){
	register Node *current;
	register Node *new;

	/* Find a right place for insertion */
	while( (current=*nextp)!= NULL && current->value<new_value ){
		nextp = &current->next;
	}

	/* init a new Node */
	new = (Node*)malloc(sizeof(Node));
	if( new == NULL ){
		fprintf(stderr,"ERROR(sll_insert):failed to init a new Node !\n");
		exit(EXIT_FAILURE);
	}
	new->value = new_value;

	/* insert the new Node into the link-list */
	new->next = current;
	*nextp = new;
}

void sll_destroy(SLList sll_node){
	register Node *next;

	while( sll_node != NULL ){
		next = sll_node->next;
		free(sll_node);
		sll_node = next;
	}
}