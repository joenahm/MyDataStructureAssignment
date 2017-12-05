#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct{
	int value;
	int index;
} blockNode;

int blockSearch(int *infoArr, int length, int key){
	int blockAmt = (int)sqrt(length);
	blockNode *blockArr = (blockNode*)malloc(sizeof(blockNode)*blockAmt);

	int maxElem = infoArr[0];
	blockArr[0].index = 0;

	int i,j;
	for( i = 0, j = 0 ; i < length ; i++ ){
		if( infoArr[i] > maxElem ){
			maxElem = infoArr[i];
		}
		
		if( (i+1)%blockAmt == 0 ){
			blockArr[j].value = maxElem;

			if( j < blockAmt ){
				j++;	
				blockArr[j].index = i+1;
			}
		}
	}
	
	for( i = 0 ; i < blockAmt ; i++ ){
		printf(" %d", blockArr[i].value);
		printf(" %d\n", blockArr[i].index);
	}

	free(blockArr);

	return index;
}

int main(void){
	int inputArr[MAX];

	int size;
	printf("input the size of data : ");
	fflush(stdout);
	scanf("%d", &size);
	int i;
	for( i = 0 ; i < size ; i++ ){
		printf("input the data[%d] : ", i);
		fflush(stdout);
		scanf("%d", &inputArr[i]);
	}

	blockSearch(inputArr,size,1);

	return 0;
}
