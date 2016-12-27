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

int main() {
	Book book("hello",17.9);
	cout << book;
}
