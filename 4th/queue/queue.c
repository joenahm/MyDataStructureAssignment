/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
 */
#include "queue.h"
#include <assert.h>

void queue_init(Queue *queuep){
	queuep->head = NULL;
	queuep->tail = NULL;	
}

int queue_isEmpty(Queue *queuep){
	int status;
	if( queuep->head == NULL ){
		status = TRUE;
	}else{
		status = FALSE;
	}

	return status;
}

void queue_in(Queue *queuep, queue_elem_type value){
	QNode *newNode = (QNode*)malloc(sizeof(QNode));
	if( newNode != NULL ){
		newNode->value = value;
		newNode->next = NULL;	
	}else{
		fprintf(stderr, "ERROR(queuep_in): faild to init new node for queue !\n");
		exit(EXIT_FAILURE);
	}

	if( queuep->tail == NULL ){
		queuep->tail = newNode;
	}else{
		queuep->tail->next = newNode;
		queuep->tail = newNode;
	}

	if( queuep->head == NULL ){
		queuep->head = newNode;
	}
}

void queue_out(Queue *queuep){
	assert(!queue_isEmpty(queuep));

	if( queuep->head == queuep->tail ){
		queuep->tail = NULL;
	}

	QNode *temp = queuep->head;
	queuep->head = queuep->head->next;
	free(temp);
}

queue_elem_type queue_getHead(Queue *queuep){
	assert(!queue_isEmpty(queuep));

	return queuep->head->value;
}

void queue_destroy(Queue *queuep){
	QNode *current = queuep->head;
	queuep->head = NULL;
	queuep->tail = NULL;
	while( current != NULL ){
		QNode *temp = current;
		current = current->next;
		free(temp);
	}
}