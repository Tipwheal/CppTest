#ifndef _E_TEXT_EDIT_H_
#define _E_TEXT_EDIT_H_

#include "EComponent.h"

using namespace std;

class ETextEdit :public EComponent{
	string name;
public:
	ETextEdit(string name) :name(name){}
	void show();
	string getName();
};

void ETextEdit::show() {
	cout << name;
}

string ETextEdit::getName() {
	return name;
}

#endif //_E_TEXT_EDIT_H_
