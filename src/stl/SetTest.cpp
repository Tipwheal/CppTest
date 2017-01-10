#include<set>
#include<iostream>

using namespace std;

int main() {
	set<int> setA;
	setA.insert(1);
	cout << "insert 1" << endl;
	setA.insert(1);
	cout << "insert 1" << endl;
	set<int>::iterator it;
	cout << "show all:" << endl;
	for(it = setA.begin(); it != setA.end();it ++) {
		cout << *it << endl;
	}
	cout << "count 1" << endl;
	cout << setA.count(1) << endl;
	cout << "erase 1,insert 2,3,4" << endl;
	setA.erase(1);
	setA.insert(2);
	setA.insert(3);
	setA.insert(4);
	cout << "print all" << endl;
	for(it = setA.begin();it != setA.end();it ++) {
		cout << *it << endl;
	}
}
