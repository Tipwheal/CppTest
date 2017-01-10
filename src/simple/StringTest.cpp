#include<iostream>

using namespace std;

int main() {
	string s = "hello";
	int i = s.find('e');
	string sub = s.substr(i);
	string sub2 = s.substr(i,1);
	cout << s << endl;
	cout << i << endl;
	cout << sub << endl;
	cout << sub2 << endl;
}
