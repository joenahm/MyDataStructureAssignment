/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
 */
#include "tbt.h"
#include "../functions.h"

/* private functions */
int isNull(tbt_elem_type value){
	int status;
	if( value.isNull ){
		status = TRUE;
	}else{
		status = FALSE;
	}

	return status;
}

void freeNode(TBTNode *node){
	//printf("free the node of value: %d\n", getData(node->value));
	free(node);
}
/* private functions */

/* public functions */
int getData(tbt_elem_type value){
	return value.data;
}

void tbt_init(TBT *rootpp){
	*rootpp = NULL;
}

void tbt_create(TBT *treeNode){
	tbt_elem_type buffer;
	getInput(&buffer);

	if( isNull(buffer) ){
		*treeNode = NULL;
	}else{
		*treeNode = (TBTNode*)malloc(sizeof(TBTNode));
		if( *treeNode != NULL ){
			(*treeNode)->value = buffer;
			(*treeNode)->lTag = NODE;
			(*treeNode)->rTag = NODE;

			tbt_create(&(*treeNode)->lChild);
			tbt_create(&(*treeNode)->rChild);
		}else{
			fprintf(stderr, "ERROR(tbt_create): failed to create binary tree node !\n");
			exit(EXIT_FAILURE);
		}	
	}
}

void tbt_preOrderTraverse(TBT treeNode, void (*visit)(TBTNode *node)){
	if( treeNode != NULL ){
		(*visit)(treeNode);

		if( treeNode->lTag != THREAD ){
			tbt_preOrderTraverse(treeNode->lChild,visit);
		}

		if( treeNode->rTag != THREAD ){
			tbt_preOrderTraverse(treeNode->rChild,visit);
		}
	}
}

void tbt_inOrderTraverse(TBT treeNode, void (*visit)(TBTNode *node)){
	if( treeNode != NULL ){
		if( treeNode->lTag != THREAD ){
			tbt_inOrderTraverse(treeNode->lChild,visit);
		}

		(*visit)(treeNode);

		if( treeNode->rTag != THREAD ){
			tbt_inOrderTraverse(treeNode->rChild,visit);
		}
	}
}

void tbt_postOrderTraverse(TBT treeNode, void(*visit)(TBTNode *nodep)){
	if( treeNode != NULL ){
		if( treeNode->lTag != THREAD ){
			tbt_postOrderTraverse(treeNode->lChild,visit);
		}

		if( treeNode->rTag != THREAD ){
			tbt_postOrderTraverse(treeNode->rChild,visit);
		}

		(*visit)(treeNode);
	}
}

void tbt_inOrderThreading(TBT treeNode, Stack *nodes){
	if( treeNode != NULL ){
		tbt_inOrderThreading(treeNode->lChild,nodes);

		
		if( !stack_isEmpty(nodes) ){
			TBTNode *temp = stack_getTop(nodes);

			if( temp->rChild == NULL ){
				temp->rChild = treeNode;
				temp->rTag = THREAD;
				printf("thread : %d -> %d\n", getData(temp->value), getData(temp->rChild->value));
				fflush(stdout);
			}else if( treeNode->lChild == NULL ){
				treeNode->lChild = temp;
				treeNode->lTag = THREAD;
				printf("thread : %d <- %d\n", getData(treeNode->lChild->value), getData(treeNode->value));
			}

			stack_pop(nodes);
		}

		stack_push(nodes,treeNode);

		tbt_inOrderThreading(treeNode->rChild,nodes);
	}
}

void tbt_destroy(TBT tree){
	tbt_postOrderTraverse(tree,&freeNode);
}
/* public functions */