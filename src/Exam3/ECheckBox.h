#ifndef _E_CHECK_BOX_H_
#define _E_CHECK_BOX_H_

#include "EComponent.h"

using namespace std;

class ECheckBox :public EComponent{
	string name;
public:
	ECheckBox(string name):name(name){}
	void show();
	string getName();
};

void ECheckBox::show() {
	cout << name << endl;
}

string ECheckBox::getName() {
	return name;
}

#endif //_E_CHECK_BOX_H_
