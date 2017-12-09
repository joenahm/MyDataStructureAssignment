/*
	快速排序(递增):
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print(int *arr, int n){
	int i;
	for( i = 0 ; i < n ; i++ ){
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int randomFisrtElem(int *arr, int low, int high){
	int index = rand()%(high-low)+low;
	int temp = arr[low];
	arr[low] = arr[index];
	arr[index] = temp;
}

int getPivot(int *arr, int low, int high){
	randomFisrtElem(arr,low,high);
	register int key = arr[low];

	while( low < high ){
		while( low < high && arr[high] >= key ){
			high--;
		}
		arr[low] = arr[high];
		while( low < high && arr[low] <= key ){
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = key;

	return low;
}

void quickSort(int *arr, int left, int right){
	if( left < right ){		
		int pivot = getPivot(arr,left,right);
		quickSort(arr,left,pivot-1);
		quickSort(arr,pivot+1,right);
	}
}



void showSort(int *arr, int n, void (*sort)(int *arr, int left, int right)){
	// register int i;	
	// for( i = n-1 ; i >= 0 ; i-- ){
	// 	arr[n-1-i] = i;
	// }
	print(arr,n);
	sort(arr,0,n-1);
	print(arr,n);
	//putchar('O');
}

int main(int argc, char const *argv[]){
	int a[999];
	int size;
	printf("input the size : ");
	fflush(stdout);
	scanf("%d", &size);

	int i;
	for( i = 0 ; i < size ; i++ ){
		printf("input a[%d] : ", i);
		fflush(stdout);
		scanf("%d", &a[i]);
	}

	srand(time(NULL)); //call it before using !!
	showSort(a,size,quickSort);
	return 0;
}
