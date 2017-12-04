/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
 */
#include "dg.h"

/* private */
int getAmt(char const *info){
	printf("%s : ", info);
	fflush(stdout);

	int temp;
	scanf("%d", &temp);

	return temp;
}


void vertAmtCheck(int *vertAmt, int inVertAmt){
	while( inVertAmt <= 0 || inVertAmt > MAX_VERT_AMT ){
		fprintf(stderr, "WARNING(vertAmtCheck): invalid amount of vertexes : %d !\n", inVertAmt);
		fflush(stderr);
		inVertAmt = getAmt("input the amount of vertexes");
	}
	
	*vertAmt = inVertAmt;
}

void edgeAmtCheck(int *edgeAmt, int inEdgeAmt){
	while( inEdgeAmt <= 0 ){
		fprintf(stderr, "WARNING(edgeAmtCheck): invalid amount of edges : %d !\n", inEdgeAmt);
		fflush(stderr);
		inEdgeAmt = getAmt("input the amount of edges");
	}

	*edgeAmt = inEdgeAmt;
}

void vertIndexCheck(int *vertIndex, int vertAmt, int orderNum){
	while( *vertIndex < 0 || *vertIndex >= vertAmt ){
		fprintf(stderr, "WARNING(vertIndexCheck): invalid index for vertex : %d !\n", *vertIndex);
		fflush(stderr);
		printf("input the start vertex for edge [%d] : ", orderNum);
		fflush(stdout);
		scanf("%d", vertIndex);
	}
}

void edgePrint(int vertNum, EdgeNode *edge_node){
	printf("vert [%d] : ", vertNum);
	while( edge_node != NULL ){
		printf(" %d", edge_node->adjVert);

		edge_node = edge_node->next;
	}
	putchar('\n');
}
/* private */

/* public */
void getInputVal(dg_elem_type *buffer){
	do{
		scanf("%c", buffer);
	}while( *buffer == '\n' );
}

void alg_init(ALGraph *alGraph){
	alGraph->vertAmt = 0;
	alGraph->edgeAmt = 0;	
}

void alg_create(ALGraph *alGraph){
	/*
	*	get the amounts of vertexes and edges
	*/
	int vertAmt,edgeAmt;
	vertAmt = getAmt("input the amount of vertexes");
	vertAmtCheck(&(alGraph->vertAmt),vertAmt);
	edgeAmt = getAmt("input the amount of edges");
	edgeAmtCheck(&(alGraph->edgeAmt),edgeAmt);

	/*
	*	get the data to store for each vertex
	*/
	int i;
	for( i = 0 ; i < alGraph->vertAmt ; i++ ){
		printf("input the data for vertex [%d] : ", i);
		fflush(stdout);
		dg_elem_type buffer;
		getInputVal(&buffer);
		alGraph->adjList[i].value = buffer;
		alGraph->adjList[i].firstEdge = NULL;
	}

	/*
	*	create infomation for each edge
	*/
	int j;
	for( j = 0 ; j < alGraph->edgeAmt ; j++ ){
		printf("input the start vertex for edge [%d] : ", j);
		fflush(stdout);
		int startVert;
		scanf("%d", &startVert);
		vertIndexCheck(&startVert,alGraph->vertAmt,j);
		printf("input the end vertex for edge [%d] : ", j);
		fflush(stdout);
		int endVert;
		scanf("%d", &endVert);
		vertIndexCheck(&endVert,alGraph->vertAmt,j);
		
		EdgeNode **linkp = &(alGraph->adjList[startVert].firstEdge);
		while( *linkp != NULL ){
			linkp = &((*linkp)->next);
		}
		EdgeNode *newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
		if( newNode != NULL ){
			newNode->adjVert = endVert;
			newNode->next = NULL;
		}else{
			fprintf(stderr, "ERROR(alg_create): faild to create edge info !\n");
			exit(EXIT_FAILURE);
		}
		*linkp = newNode;
	}

	/*
	*	print the infomation of each edge
	*/
	for( i = 0 ; i < alGraph->vertAmt ; i++ ){
		edgePrint(i,alGraph->adjList[i].firstEdge);
	}
}

void visitPrint(ALGraph *alGraph, int index){
	printf("%c ", alGraph->adjList[index].value);	
	fflush(stdout);
}

int visitedArr[MAX_VERT_AMT];
void (*visitFunc)(ALGraph *alGraph,int index);

void alg_BFSTraverse(ALGraph *alGraph, void (*visit)(ALGraph *alGraph, int index)){
	int i;
	for( i = 0 ; i < alGraph->vertAmt ; i++ ){
		visitedArr[i] = FALSE;
	}

	Queue vertIndexQue;
	queue_init(&vertIndexQue);

	visitFunc = visitPrint;
	for( i = 0 ; i < alGraph->vertAmt ; i++ ){
		if( visitedArr[i] == FALSE ){
			visitedArr[i] = TRUE;
			visitFunc(alGraph,i);

			queue_in(&vertIndexQue,i);

			while( !queue_isEmpty(&vertIndexQue) ){
				int currentIndex = queue_getHead(&vertIndexQue);
				queue_out(&vertIndexQue);

				EdgeNode *currentEdgeNode = alGraph->adjList[currentIndex].firstEdge;
				while( currentEdgeNode != NULL ){
					int index = currentEdgeNode->adjVert;
					if( visitedArr[index] == FALSE ){
						visitedArr[index] = TRUE;
						visitFunc(alGraph,index);

						queue_in(&vertIndexQue,index);
					}

					currentEdgeNode = currentEdgeNode->next;
				}
			}
		}
	}

	queue_destroy(&vertIndexQue);
}
/* public */
