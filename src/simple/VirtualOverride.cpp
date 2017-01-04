#include<iostream>

using namespace std;

//只是继承的时候木有问题（没有方法的话)
//有方法，不调用也没有问题。。
//调用了就有问题啦
//重载一个方法再菱形继承会有问题,当然不重载也有问题(不用虚继承时)
//虚继承，不重载，不同时重载，木有问题


class Father {
public:
	virtual string hello() {return "father's hello";}
	virtual string cry() {return "father's cry";}
};

class ElderSon : public virtual Father {
public:
	virtual string hello(){return "elder son's hello";}
};

class YoungerSon : public virtual Father{
public:
	virtual string cry(){return "younger son's cry";}
};

class StrangeGrandson : public ElderSon,public YoungerSon {

};

int main() {
	StrangeGrandson s;
	cout << s.hello() << endl;
	cout << s.cry() << endl;
}
