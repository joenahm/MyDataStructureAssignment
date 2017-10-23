#ifndef _stack_h_
#define _stack_h_

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template<class T>
class Stack{
private:
    //  T* base;    no use
    //  T* top;     no use
    vector<T>* vec;
public:
    Stack();
    Stack(const Stack<T>&);
    Stack<T>& operator=(const Stack<T>&);
    ~Stack();
    void clear();
    bool isEmpty();
    int length();
    T getTop();
    T push(T value_to_push);
    T pop();
  //  T traverse(T (*visit)());    need to implement visit()
};

template<class T>
Stack<T>::Stack(){
    vec = new vector<T>;
    if(vec == NULL){
    	cerr << "ERROR(Stack::Stack()):init vector faild !" << endl;
        exit(EXIT_FAILURE);
    }
}

template<class T>
Stack<T>::Stack(const Stack<T>& newStack){
    vec = new vector<T>;
    vec =newStack.vec;
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& newStack){
    delete vec;

    vec = new vector<T>;
    vec =newStack.vec;

    return *this;
}

template<class T>
Stack<T>::~Stack(){
    delete vec;
}

template<class T>
void Stack<T>::clear(){
    vec->clear();
}

template<class T>
bool Stack<T>::isEmpty(){
    bool IoN;    //means "is or not"

    if(vec->size()==0)
        IoN=true;
    else
        IoN=false;

    return IoN;
}

template<class T>
int Stack<T>::length(){
    return vec->size();
}

template<class T>
T Stack<T>::getTop(){
    return vec->back();
}

template<class T>
T Stack<T>::push(T val){
    vec->push_back(val);

    return val;
}

template<class T>
T Stack<T>::pop(){
    T temp;

    temp=vec->back();

    vec->pop_back();

    return temp;
}


#endif
