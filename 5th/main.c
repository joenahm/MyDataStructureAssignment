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
	
	int blockIndex = -1;
	int flag = -1;
	int low = 0;
	int high = blockAmt-1;
	while( low<=high ){
		register int mid = (low+high)/2;
		if( blockArr[mid].value >= key ){
			if( blockArr[mid-1].value<key
			|| mid == 0 ){

				blockIndex = blockArr[mid].index;
				flag = blockArr[mid].value;
				break;
			}else{
				high = mid-1;
			}
		}else{
			low = mid+1;
		}
	}

	int index = -1;
	if( flag != -1 ){
		int i;
		for( i = blockIndex ; infoArr[i] <= flag ; i++ ){
			if( infoArr[i] == key ){
				index = i;
				break;
			}
		}
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

	printf("input the key you want to search : ");
	fflush(stdout);
	int key;
	scanf("%d", &key);

	printf("%d", blockSearch(inputArr,size,key));

	return 0;
}
