#include "header.h"

/*
 *	NOTICE:
 *		The Queue in this file cannot be put into using !
 *		Because it is whithout destroy() function .
 */

typedef struct QNODE{
	int value;
	struct QNODE *next;
} QNode;

typedef struct{
	QNode *tail;
} Queue;

void q_init(Queue *q){
	QNode *newNode = (QNode*)malloc(sizeof(QNode));
	if( newNode != NULL ){
		newNode->value = 'H';
		newNode->next = newNode;
		q->tail = newNode;
	}else{
		fprintf(stderr,"ERROR(q_init): faild to init the queue !\n");
	}
	
}

void q_in(Queue *q, int val){
	QNode *newNode = (QNode*)malloc(sizeof(QNode));
	if( newNode != NULL ){
		newNode->value = val;
		newNode->next = q->tail->next; //set newNode->next to the Head-Node
		q->tail->next = newNode; //link the newNode to the last of the queue
		q->tail = newNode; //set tail-pointer to newNode
	}else{
		fprintf(stderr,"ERROR(q_in): faild to enqueue !\n");
	}
}

int q_out(Queue *q){
	QNode *headNode = q->tail->next;
	QNode *toOut = headNode->next;
	int val = toOut->value;
	headNode->next = toOut->next;
	free(toOut);

	return val;
}

int main(int argc, char const *argv[]){
	Queue queue;
	q_init(&queue);
	q_in(&queue,22);
	q_in(&queue,33);
	printf("%d\n", q_out(&queue));
	printf("%d\n", q_out(&queue));

	return 0;
 }
