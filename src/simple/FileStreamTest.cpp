#include<fstream>
#include<iostream>

using namespace std;

int main() {
	ofstream out("a.txt",ios::out);
	out << "test";
	out.close();

	ifstream in("a.txt",ios::in);
	string s;
	in >> s;
	cout << s;
	in.close();

	ofstream out2("a.txt",ios::app);
	out2 << "\ntest";
	out2.close();
}
