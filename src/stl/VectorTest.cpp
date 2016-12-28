#include<vector>
#include<iostream>
#include<algorithm>	//thi file contains reverse and sort

using namespace std;

class Foo {
	string name;
	int age;
public:
	Foo(string name,int age):name(name),age(age){}
	int getAge();
	friend ostream& operator<<(ostream& os,const Foo& foo);
	bool operator>(Foo& another);
	bool operator<(Foo& another);
};

int Foo::getAge() {
	return age;
}

ostream& operator<<(ostream& os,const Foo& foo) {
	os << foo.name;
}

bool Foo::operator>(Foo& another) {
	return age > another.age;
}

bool Foo::operator<(Foo& another) {
	return age < another.age;
}

int main() {
	vector<Foo> v;
	Foo a("test",10);
	v.push_back(a);
	Foo b("second",2);
	v.push_back(b);

	//iterator
	cout << "after push two:" << endl;
	vector<Foo>::iterator it;
	for(it = v.begin();it != v.end();it ++) {
		cout << *it << endl;
	}
	cout << endl;

	//[] and insert
	cout << "insert to second pos:" << endl;
	v.insert(v.begin()+1,a);
	cout << v[0] << " " << v[1] << endl;
	cout << endl;

	//erase
	cout << "erase last two and clear:" << endl;
	v.erase(v.begin()+1,v.end());
	cout << "size: " <<v.size() << endl;
	v.clear();
	cout << "size: "<< v.size() << endl;
	cout << endl;

	//reverse and sort
	Foo c("third",13);
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	cout << "push \"test\", \"second\" and \"third\", reverse last two:" << endl;
	reverse(v.begin()+1,v.end());
	for(int i = 0;i<v.size();i++) {
		cout << v[i] << endl;
	}
	cout << "sort by age:" << endl;
	sort(v.begin(),v.end(),[](Foo &a,Foo &b){return a > b;});	//from max to min
	for(int i = 0;i<v.size();i++) {
		cout << v[i] << endl;
	}
}
