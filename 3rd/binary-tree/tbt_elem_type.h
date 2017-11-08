/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
 */
#ifndef _TBT_ELEM_TYPE_
#define _TBT_ELEM_TYPE_

typedef struct{
	int data;
	int isNull;
} tbt_elem_type;

typedef struct TBTNODE{
	tbt_elem_type value;
	struct TBTNODE *lChild;
	struct TBTNODE *rChild;
	int lTag;
	int rTag;
} TBTNode, *TBT;

#endif