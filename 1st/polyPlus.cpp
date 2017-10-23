#include "stack.hpp"
#include "linkedList.hpp"
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>

const int NUM_MAX = 100;

void popTo(Stack<char> &stack,int &coe,const char flag){
	char temp[NUM_MAX];
	temp[NUM_MAX-1] = '\0';
	int i = NUM_MAX - 22;

	while( !stack.isEmpty() && i >= 0 ){
		temp[i] = stack.pop();

		i--;
	}

	coe = atoi(&temp[i+1]);

	if( flag == '-' )
		coe = -coe;
}
void popTo(Stack<char> &stack,int &exp){
	char temp[NUM_MAX];
	temp[NUM_MAX-1] = '\0';
	int i = NUM_MAX - 2;

	while( !stack.isEmpty() && i >= 0 ){
		temp[i] = stack.pop();

		i--;
	}

	exp = atoi(&temp[i+1]);
}
void sTol(const char* s, LL &l){ 	/* string to linkedList */
	char flag = '+';	/* data init begin */
	int coe = 0 , exp = 0;
	Stack<char> stack;
	int i = 0;	/* data init over */

	while( s[i] != '\0' ){	//polyString loop
		if( s[i] == '-' || s[i] == '+' ){
			if( !stack.isEmpty() ){
				if( coe == 0 ){
					popTo(stack,coe,flag);//get coe

					Data d;//
					d.coe = coe;//
					d.exp = 0;//
					l.insert(d);//make Node(coe,0)
				}
				else{
					popTo(stack,exp);//get exp

					Data d;	//
					d.coe = coe;//
					d.exp =exp;//
					l.insert(d);//make Node(coe,exp)
				}
			}

			if( s[i] == '+' )
				flag = '+';
			else if( s[i] == '-' )
				flag = '-';
		}else if( s[i] == 'x' ){
			if( !stack.isEmpty() )
				popTo(stack,coe,flag);
			else{
				if( flag == '+' )
					coe = 1;
				else
					coe = -1;
			}
			
			stack.push('1');
		}else if( s[i]>='0' && s[i]<='9' )
			stack.push(s[i]);
		else if( s[i] == '^' ){
			if( !stack.isEmpty() )
				stack.pop();
		}else{
			cerr << "ERROR(sTol()):poly is invalid !" << endl;
			exit(EXIT_FAILURE);
		}

		i++;
	}

	if( !stack.isEmpty() ){
		if( coe == 0 ){
			popTo(stack,coe,flag);

			Data d;
			d.coe = coe;
			d.exp = 0;
			l.insert(d);
		}else{
			popTo(stack,exp);

			Data d;
			d.coe = coe;
			d.exp = exp;
			l.insert(d);
		}
	}
}
void polyPlus(string p1, string p2, string& pOut){
	const char* s1 = p1.c_str();
	const char* s2 = p2.c_str();

	LL l1,l2;

	sTol(s1,l1);	//提取s1的系数和指数,指数到链表l1
	sTol(s2,l2);	//提取s2的系数和指数,指数到链表l2

	Node* temp1 = l1.getHead()->next;	/* 合并同类项开始 */
	while( temp1 != NULL ){
		int exp1 = temp1->value.exp;
		Node* temp2 = l2.getHead()->next;
		Node* buff = NULL;

		while( temp2 != NULL ){
			int exp2 = temp2->value.exp;

			if( temp2->next == NULL && exp2 < exp1 ){
				temp2->next = new Node(temp1->value);

				break;
			}
			else if( exp2 < exp1 && exp1 < temp2->next->value.exp ){
				buff = temp2->next;
				temp2->next = new Node(temp1->value);
				temp2->next->next = buff;

				break;
			}else if( exp1 < exp2 ){
				buff = l2.getHead()->next;
				l2.getHead()->next = new Node(temp1->value);
				l2.getHead()->next->next = buff;

				break;
			}else if( exp2 == exp1 ){
				temp2->value.coe += temp1->value.coe;

				break;
			}

			temp2 = temp2->next;
		}

		temp1 = temp1->next;
	}/* 合并同类项结束，结果保存于l2中 */

	bool isFirst = true;	/* 构造输出字符串开始 */
	Node* t = l2.getHead()->next;
	while( t != NULL ){
		int coe = t->value.coe;
		int exp = t->value.exp;
		stringstream ss1,ss2;
		string coeStr,expStr;
		ss1 << coe;
		ss1 >> coeStr;
		ss2 << exp;
		ss2 >> expStr;
		if( coe != 0 ){
			if( coe > 0 && !isFirst )
				pOut += '+';

			if( exp == 0 )
				pOut += coeStr;
			else{
				if( coe != 1 && coe != -1 )
					pOut += coeStr;
				else if( coe == -1 )
					pOut += '-';

				pOut += 'x';

				if( exp != 1 )
					pOut += ("^"+expStr);
			}

			isFirst = false;
		}
		t = t->next;
	}	/* 构造输出字符串结束 */
}

int main(){
	string poly1,poly2,polyOut;

	cout << "poly1:";
	cin >> poly1;

	cout << "poly2:";
	cin >> poly2;


	polyPlus(poly1,poly2,polyOut);

	cout << endl << polyOut << endl;

	return 0;
}
