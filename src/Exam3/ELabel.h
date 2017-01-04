#ifndef _E_LABEL_H_
#define _E_LABEL_H_

#include "EComponent.h"

using namespace std;

class ELabel :public EComponent{
	string name;
public:
	ELabel(string name) :name(name){};
	void show();
	string getName();
};

void ELabel::show() {
	cout << name << endl;
}

string ELabel::getName() {
	return name;
}

#endif //_E_LABEL_H_
