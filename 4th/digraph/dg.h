/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
	Version	:	v0.1

	digraph

	"queue" needed !

	NOTICE:
	Check the definition of 'elem_type' in 'queue_elem_type.h' 
	before using !!

	Define the 'dg_elem_type' in 'dg_elem_type.h' before using !!

 */
#ifndef _DG_H__
#define _DG_H_

#include <stdio.h>
#include <stdlib.h>
#include "dg_elem_type.h"
#include "../queue/queue.h"


#define MAX_VERT_AMT 100

#define TRUE 1
#define FALSE 0

typedef struct EDGENODE{
	int adjVert;
	struct EDGENODE *next;
} EdgeNode;

typedef struct VERTNODE{
	dg_elem_type value;
	EdgeNode *firstEdge;
} VertNode;

typedef struct{
	int vertAmt;
	int edgeAmt;
	VertNode adjList[MAX_VERT_AMT];
} ALGraph;

void alg_init(ALGraph *alGraph);
void alg_create(ALGraph *alGraph);
void alg_BFSTraverse(ALGraph *alGraph, void (*visit)(ALGraph *alGraph, int index));

void getInputVal(dg_elem_type *buffer);
void visitPrint(ALGraph *alGraph, int index);

#endif
