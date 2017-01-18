#include<iostream>

using namespace std;

class Determinant {
	int size;
	int *data;
public:
	Determinant(int size,int *data);
	~Determinant();
	Determinant(const Determinant& copy);
	void input(int size,int *data);
	int getSize();
	int operator[](int index);
	int getValue();
	Determinant* getRemainder(int row,int col);
	Determinant* operator+(const Determinant& another);
	Determinant* operator-();
	Determinant* operator-(const Determinant& another);
};

void Determinant::input(int size,int *data) {
	this -> size = size;
	this -> data = data;
}

Determinant::Determinant(int size,int *data)
	:size(size),data(data){}

Determinant::~Determinant() {
	delete data;
}

Determinant::Determinant(const Determinant& copy)
	:size(copy.size),data(copy.data){}

int Determinant::getSize() {
	return size;
}

int Determinant::operator[](int index) {
	return data[index];
}

int Determinant::getValue() {
	if(size == 1) return data[0];
	if(size == 2) return data[0]*data[3] - data[1]*data[2];
	int result = 0;
	for(int i = 0;i<size;i++) {
		if(i%2 == 0) {
			result += (*this)[i]*(this -> getRemainder(0,i) -> getValue());
		}else {
			result -= (*this)[i]*(this -> getRemainder(0,i) -> getValue());
		}
	}
	return result;
}

Determinant* Determinant::getRemainder(int row,int col) {
	int size = this -> size - 1;
	int count = 0;
	int *data = new int;
	for(int i = 0;i<this -> size*this -> size;i++) {
		if((i >= row*(this -> size) && i < (row+1)*(this -> size)) || (i - col)%(this -> size) == 0) {			
		}else {
			data[count++] = (*this)[i];
		}
	}
	Determinant *d = new Determinant(size,data);
	return d;
}

Determinant* Determinant::operator+(const Determinant& another) {
	if(this -> size != another.size) return NULL;
	int *data = new int[size*size];	
	for(int i = 0;i<size*size;i++) {
		data[i] = (this -> data)[i] + another.data[i];
	}
	Determinant *result = new Determinant(size,data);
	return result;
}

Determinant* Determinant::operator-() {

}

Determinant* Determinant::operator-(const Determinant& another) {

}

int main() {
	int *data = new int[9]{1,2,4,2,4,8,7,8,8};
	Determinant a(3,data);
	for(int i = 0;i<a.getSize()*a.getSize();i++) {
		cout << a[i] << endl;
	}
	Determinant *another = a.getRemainder(0,2);
	for(int i = 0;i<another -> getSize()*another -> getSize();i++) {
		cout << (*another)[i] << endl;
	}
	cout << "value" <<a.getValue() << endl;
}
