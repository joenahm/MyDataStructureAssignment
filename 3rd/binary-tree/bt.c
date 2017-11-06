/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
 */
#include "bt.h"
#include "../functions.h"

/* private functions */
int isNull(bt_elem_type value){
	int status;
	if( value.isNull ){
		status = TRUE;
	}else{
		status = FALSE;
	}

	return status;
}

void freeNode(BTNode *node){
	if( bt_isLeaf(*node) ){
		printf("free the node of value: %d\n", getData(node->value));
		free(node);
	}
}
/* private functions */

/* public functions */
int getData(bt_elem_type value){
	return value.data;
}

void bt_init(BT *rootpp){
	*rootpp = NULL;
}

void bt_create(BT *treeNode){
	bt_elem_type buffer;
	getInput(&buffer);

	if( isNull(buffer) ){
		*treeNode = NULL;
	}else{
		*treeNode = (BTNode*)malloc(sizeof(BTNode));
		if( *treeNode != NULL ){
			(*treeNode)->value = buffer;

			bt_create(&(*treeNode)->lChild);
			bt_create(&(*treeNode)->rChild);
		}else{
			fprintf(stderr, "ERROR(bt_create): failed to create binary tree node !\n");
			exit(EXIT_FAILURE);
		}	
	}
}

int bt_isLeaf(BTNode node){
	int status;
	if( node.lChild == NULL
		&& node.rChild == NULL ){

		status = TRUE;
	}else{
		status =FALSE;
	}

	return status;
}

void bt_inOrderTraverse(BT treeNode, void (*visit)(BTNode *node)){
	if( treeNode != NULL ){
		bt_inOrderTraverse(treeNode->lChild,visit);
		(*visit)(treeNode);
		bt_inOrderTraverse(treeNode->rChild,visit);
	}
}

void bt_postOrderTraverse(BT treeNode, void(*visit)(BTNode *nodep)){
	if( treeNode != NULL ){
		bt_inOrderTraverse(treeNode->lChild,visit);
		bt_inOrderTraverse(treeNode->rChild,visit);
		(*visit)(treeNode);
	}
}

void bt_destroy(BT tree){
	bt_postOrderTraverse(tree,&freeNode);
}
/* public functions */