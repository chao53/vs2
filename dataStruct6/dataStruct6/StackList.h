#pragma once
#include <iostream>
using namespace std;

template<class T>class StackList {
private:
	T* data; //指针数组
	int max_size;
	int top;
	void initStack();
public:
	StackList();
	StackList(int max_size);
	~StackList();
	int isEmpty();
	int isFull();
	int push(T x);
	int pop(T& x);
	T show();
	void clear();
};

template<class T>
void StackList<T>::initStack() {
    data = new T[max_size];//分配栈空间
    top = -1;//初始化栈顶
}

template<class T>
StackList<T>::StackList(int max_size) {
    this->max_size = max_size;
    initStack();
}

template<class T>
StackList<T>::~StackList() {
    delete data;
}

template<class T>
int StackList<T>::isEmpty() {
    return (top == -1) ? 1 : 0;
}


template<class T>
int StackList<T>::isFull() {
    return (top >= max_size) ? 1 : 0;
}

template<class T>
int StackList<T>::push(T x) {
    if (isFull()) {
        return 0;
    }
    else {
        top++;
        data[top] = x;
    }
    return 1;
}

template<class T>
int StackList<T>::pop(T& x) {
    if (isEmpty()) {
        return 0;
    }
    else {
        x = data[top];
        top--;
    }
    return 1;
}

template<class T>
T StackList<T>::show() {
    if (isEmpty()) {
        return '#';
    }
    else
    {
        return data[top];
    }
}

template<class T>
void StackList<T>::clear() {
    top = -1;
}