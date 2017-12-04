#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int blockSearch(int *infoArr, int length, int key){
	int index = 0;
	int blockAmt = (int)sqrt(length);
	int *blockArr = (int*)malloc(sizeof(int)*blockAmt);
	int maxElem = infoArr[0];
	int i,j;
	for( i = 0, j = 0 ; i < length ; i++ ){
		if( i!=0 && i%blockAmt == 0 ){
			blockArr[j] = maxElem;
			j++;	
		}

		if( infoArr[i] > maxElem ){
			maxElem = infoArr[i];
		}
	}
	
	for( i = 0 ; i < blockAmt ; i++ ){
		printf(" %d", blockArr[i]);
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
