/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
 */
#include "sllist.h"

void sll_init(SLList *sll_headpp){
	Node *headNode = (Node*)malloc(sizeof(Node));
	headNode->value = 'H';
	headNode->next = NULL;

	*sll_headpp = headNode;
}

void sll_print(SLList sll_node){
	sll_node = sll_node->next;
	while( sll_node != NULL ){
		printf(" %d", sll_node->value);

		sll_node = sll_node->next;
	}
	putchar('\n');
}

void sll_insert(SLList sll_headNode, elem_type new_value){
	register Node *current;
	register Node **nextp = &(sll_headNode->next);

	/* Find a right place for insertion */
	while( (current=*nextp)!= NULL && current->value<new_value ){
		nextp = &current->next;
	}

	/* init a new Node */
	register Node *new;
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