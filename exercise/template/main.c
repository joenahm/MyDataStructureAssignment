#include "header.h"

int main(int argc, char const *argv[]){
	SqList sql1;
	sql_init(&sql1,10);
	sql_insert(&sql1,0,1);
	printf("%d\n", sql_get(&sql1,0));
	sql_destroy(&sql1);

	return 0;
 }
