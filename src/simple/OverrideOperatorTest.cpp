#include<iostream>

using namespace std;

class Book {
	string name;
	double price;
public :
	Book(string name,double price);
	friend ostream& operator<<(ostream& os,const Book book);
};

Book::Book(string name,double price)
	:name(name),price(price) {}

ostream& operator<<(ostream& os,const Book book) {
	return os << book.name << " " << book.price;
}

class Complex {
	double real;
	double index;
public:
	Complex(double r,double i);
	Complex operator-();
	Complex operator-(const Complex& b);
	friend ostream& operator<<(ostream& os,const Complex& c);
	//friend Complex operator-(const Complex& a,const Complex& b);
};

Complex::Complex(double r,double i)
	:real(r),index(i){}

Complex Complex::operator-() {
	return Complex(-real,-index);
}

Complex Complex::operator-(const Complex& b) {
	return Complex(this -> real - b.real,this -> index - b.index);
}

ostream& operator<<(ostream& os,const Complex& c) {
	if(!(c.real || c.index)) os << 0;
	else if(!c.real) os << c.index << "i";
	else if(!c.index) os << c.real;
	else os << c.real << "+" << c.index << "i";
}

int main() {
	Book book("hello",17.9);
	cout << book << endl;
	Complex a(2,2);
	Complex b(2,3);
	cout << a - b << endl;	
}
