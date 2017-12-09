/*
	折半插入排序(递增):
*/
#include <stdio.h>

void print(int *arr, int n){
	int i;
	for( i = 0 ; i < n ; i++ ){
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void binaryInsertionSort(int *arr, int n){
	register int i;
	register int key;
	for( i = 1 ; i < n ; i++ ){
		if( arr[i] < arr[i-1] ){
			// putchar('\n');
			key = arr[i];

			int low = 0;
			int high = i - 1;
			while( low <= high ){
				int mid = (low+high)/2;
				if( arr[mid] < key ){
					low = mid+1;
				}else{
					high = mid-1;
				}
			}
			
			int j;
			for( j = i-1 ; j > high ; j-- ){
				arr[j+1] = arr[j];
			}

			arr[high+1] = key;
			// print(arr,n);
		}
	}
}

void showSort(int *arr, int n, void (*sort)(int *arr, int n)){
	// register int i;	
	// for( i = n-1 ; i >= 0 ; i-- ){
	// 	arr[n-1-i] = i;
	// }
	print(arr,n);
	sort(arr,n);
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

	showSort(a,size,binaryInsertionSort);
	return 0;
}
