#include<iostream>

using namespace std;

// 记得用c++11以上的标准…

int main() {
	string name = "hello";
	string addr = "china";
	auto func = [](){cout << "test" << endl;};		//分号要加上
	auto noParam = []{cout << "no param is ok" << endl;};
	auto outName = [name]{cout << name << endl;};
	auto outRef = [&](int times){
		for(int i = 0;i < times;i ++) {	
			cout << name << "," << addr << endl;
		}
	};
	func();
	noParam();
	outName();
	outRef(2);
}
