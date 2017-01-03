#include<iostream>

using namespace std;

class Trash {
	int index;
public:
	Trash();
	Trash(const Trash& src);
	~Trash();
	friend istream& operator>>(istream& is,Trash& t);
	friend ostream& operator<<(ostream& os,const Trash& t);
};

Trash::Trash():index(1) {}

Trash::Trash(const Trash& src) {
	cout << "here" << endl;
	index = src.index + 1;
}

Trash::~Trash() {}

istream& operator>>(istream& is,Trash& t) {
	is >> t.index;
}

ostream& operator<<(ostream& os,const Trash& t) {
	os << t.index;
}

void testFunc() {
	Trash t;
	cout << t << endl;
	throw t;	//throw时一定会发生复制
}

int main() {
	try {
		testFunc();
	}catch (Trash& t) {
		cout << t;
	}
}
