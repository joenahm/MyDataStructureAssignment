/* 
	Author	:	Joe Nahm
	Email	:	joenahm@yeah.net
 */
#ifndef _BT_ELEM_TYPE_
#define _BT_ELEM_TYPE_

typedef struct{
	int data;
	int isNull;
} bt_elem_type;

typedef struct BTNODE{
	bt_elem_type value;
	struct BTNODE *lChild;
	struct BTNODE *rChild;
} BTNode, *BT;

#endif