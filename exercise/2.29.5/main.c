#include "header.h"

void alignBC(SqList *sqlA, int key, SqList *sqlB, int *iB, SqList *sqlC, int *iC){
	while( (*iB<sql_getLen(sqlB)&&*iC<sql_getLen(sqlC))
		&& (sql_get(sqlB,*iB)<sql_get(sqlA,key)
			|| sql_get(sqlC,*iC)<sql_get(sqlA,key)) ){

		if( sql_get(sqlB,*iB)<sql_get(sqlA,key) ){
			*iB += 1;
		}
		if( sql_get(sqlC,*iC)<sql_get(sqlA,key) ){
			*iC += 1;
		}
	}
}

void alignA(SqList *sqlA, int *key, SqList *sqlB, int iB, SqList *sqlC, int iC){
	while( (*key<sql_getLen(sqlA))
		&& (sql_get(sqlA,*key)<sql_get(sqlB,iB)
			|| sql_get(sqlA,*key)<sql_get(sqlC,iC)) ){

		*key += 1;
	}
}

void delKeyVal(SqList *sqlA, int key, SqList *sqlB, int *iB, SqList *sqlC, int *iC){
	if( sql_get(sqlA,key)==sql_get(sqlB,*iB)
	&& sql_get(sqlA,key)==sql_get(sqlC,*iC) ){

		while( key+1 < sql_getLen(sqlA) ){
			sql_set(sqlA,key,sql_get(sqlA,key+1));
			key++;
		}
		sql_setLen(sqlA,sql_getLen(sqlA)-1);
	}

	if( sql_get(sqlA,key)!=sql_get(sqlB,*iB)
	&& sql_get(sqlA,key)!=sql_get(sqlC,*iC) ){
		
		*iB += 1;
		*iC += 1;
	}
}

void delVinBC(SqList *sqlA, SqList *sqlB, SqList *sqlC){
	int key,iB,iC;
	key = iB = iC = 0;

	while( key < sql_getLen(sqlA)
		&& iB < sql_getLen(sqlB)
		&& iC < sql_getLen(sqlC) ){

		alignBC(sqlA,key,sqlB,&iB,sqlC,&iC);
		alignA(sqlA,&key,sqlB,iB,sqlC,iC);
		alignBC(sqlA,key,sqlB,&iB,sqlC,&iC);
		delKeyVal(sqlA,key,sqlB,&iB,sqlC,&iC);
	}
}

int main(int argc, char const *argv[]){
	SqList sqlA,sqlB,sqlC;
	sql_init(&sqlA,10);
	sql_init(&sqlB,10);
	sql_init(&sqlC,10);

	sql_insert(&sqlA,0,1);
	sql_insert(&sqlA,1,3);
	sql_insert(&sqlA,2,4);
	sql_insert(&sqlA,3,5);
	sql_insert(&sqlA,4,10);
	sql_insert(&sqlA,5,10);

	sql_insert(&sqlB,0,3);
	sql_insert(&sqlB,1,3);
	sql_insert(&sqlB,2,10);
	sql_insert(&sqlB,3,10);
	sql_insert(&sqlB,4,11);
	sql_insert(&sqlB,5,30);
	sql_insert(&sqlB,6,30);

	sql_insert(&sqlC,0,3);
	sql_insert(&sqlC,1,5);
	sql_insert(&sqlC,2,10);
	sql_insert(&sqlC,3,11);
	sql_insert(&sqlC,4,44);
	sql_insert(&sqlC,5,55);

	sql_print(&sqlA,sql_getLen(&sqlA));
	sql_print(&sqlB,sql_getLen(&sqlB));
	sql_print(&sqlC,sql_getLen(&sqlC));

	delVinBC(&sqlA,&sqlB,&sqlC);

	sql_print(&sqlA,sql_getLen(&sqlA));

	sql_destroy(&sqlA);
	sql_destroy(&sqlB);
	sql_destroy(&sqlC);

	return 0;
 }
