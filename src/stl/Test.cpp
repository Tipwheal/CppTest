#include "MyVector.hpp"

using namespace std;

int main() {
	MyVector<int> *v = new MyVector<int>;
	delete[] v;
	v = new MyVector<int>;
}
