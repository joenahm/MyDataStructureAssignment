/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
	Version	:	v0.1

	NOTICE:
	Define the 'elem_type' in 'queue_elem_type.h' before using !!
	The 'elem_type' defaultly is 'int'
 */
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "queue_elem_type.h"

#define TRUE 1
#define FALSE 0

typedef struct QNODE{
	queue_elem_type value;
	struct QNODE *next;
} QNode;

typedef struct{
	QNode *head;
	QNode *tail;
} Queue;
	
void queue_init(Queue *queuep);
int queuep_isEmpty(Queue *queuep);
void queue_in(Queue *queuep, queue_elem_type value);
void queue_out(Queue *queuep);
queue_elem_type queue_getHead(Queue *queuep);
void queue_destroy(Queue *queuep);

#endif