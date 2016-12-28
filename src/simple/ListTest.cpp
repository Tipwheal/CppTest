#include<iostream>
#include<list>

using namespace std;

int main() {
	list<int>::iterator i;
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	for(i = l1.begin();i != l1.end();i++) {
		cout << *i;
	}
	cout << "end" <<endl;
	list<int*>::iterator i2;
	list<int*> l2;
	int *array1 = new int[3]{1,2,3};
	int *array2 = new int[4]{6,7,5,4};
	l2.push_back(array1);
	l2.push_back(array2);
	for(i2 = l2.begin();i2 != l2.end();i2++) {
		for(int j = 0;j<3;j++) {
			cout << (*i2)[j] << ' ';
		}
		cout << endl;
	}
}
