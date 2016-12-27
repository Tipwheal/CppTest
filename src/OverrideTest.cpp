#include<iostream>

using namespace std;

class A {
public:
	virtual void print() {cout << "a" << endl;}
};

class B : public A {
public:
	void print() {cout << "b" << endl;}
};

int main() {
	A *a = new A();
	A *b = new B();
	a -> print();
	b -> print();
}
