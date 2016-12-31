#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_

#include<iostream>

using namespace std;

typename<template>
class MyVectorNode {
public:
	T *content;
	MyVectorNode<T> *next;
	MyVectorNode(T& t);
};

template<typename T>
MyVectorNode<T>::MyVectorNode(T& t)
	:content(t),next(NULL) {
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
MyVector<T>::MyVector():first(new MyVectorNode()) {

}

template<typename T>
MyVector<T>::~MyVector() {

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

}

template<typename T>
void MyVector<T>::insert() {

}

template<typename T>
T& MyVector<T>::operator[](int index) {

}

#endif //_MY_VECTOR_H_
