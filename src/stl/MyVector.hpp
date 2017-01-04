#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_

#include<iostream>

using namespace std;

template<typename T>
class MyVectorNode {
public:
	T *content;
	MyVectorNode<T> *next;
	MyVectorNode(T& t);
	~MyVectorNode();
};

template<typename T>
MyVectorNode<T>::MyVectorNode(T& t)
	:content(t),next(NULL) {
	cout << "in Node constr" << endl;
}

template<typename T>
MyVectorNode<T>::~MyVectorNode() {
	cout << "in node destr" << endl;
	delete[] content;
	delete[] next;
}

template<typename T>
class MyVector {
	MyVectorNode<T> *first;
public:
	class iterator {};
	MyVector();
	~MyVector();
	void push_back(T& t);
	void clear();
	void insert();
	T& operator[](int index);
};

template<typename T>
MyVector<T>::MyVector()
	:first(NULL) {
	cout << "in vec constr" << endl;
}

template<typename T>
MyVector<T>::~MyVector() {
	cout << "in vec destr" << endl;
	cout << first << endl;
	if(first == NULL)
		return;
	MyVectorNode<T> *cur = first;
	MyVectorNode<T> *prev = NULL;
	while(cur -> next != NULL) {
		prev = cur;
		cur = cur -> next;
		delete[] prev;
	}
	delete[] cur;
}

template<typename T>
void MyVector<T>::push_back(T& t) {
	if(first == NULL) {
		first = new MyVectorNode<T>(t);
	}else {
		MyVectorNode<T> *current = first;
		while(current -> next != NULL) {
			current = current -> next;
		}
		current -> next = new MyVectorNode<T>(t);
	}
}

template<typename T>
void MyVector<T>::clear() {
	MyVectorNode<T> *cur = first;
	MyVectorNode<T> *prev = NULL;
	while(cur -> next != NULL) {
		prev = cur;
		cur = cur -> next;
		delete[] prev;
	}
	delete[] cur;
	first = NULL;
}

template<typename T>
void MyVector<T>::insert() {

}

template<typename T>
T& MyVector<T>::operator[](int index) {
	MyVectorNode<T> *cur = first;
	for(int i = 0;i<index;i++) {
		cur = cur -> next;
	}
	return cur -> content;
}

#endif //_MY_VECTOR_H_
