#ifndef _E_BUTTON_H_
#define _E_BUTTON_H_

#include "EComponent.h"

using namespace std;

class EButton :public EComponent{
	string name;
public:
	EButton(string name) :name(name){}
	void show();
	string getName();
};

void EButton::show() {
	cout << name << endl;
}

string EButton::getName() {
	return name;
}

#endif //_E_BUTTON_H_
