#ifndef _E_WINDOW_H_
#define _E_WINDOW_H_

#include "EContainer.h"
#include "EComponent.h"

using namespace std;

class EWindow:public EContainer,public EComponent {
	string name;
public:
	EWindow(string name) :name(name){}
	string getName();
};

string EWindow::getName() {
	return name;
}

#endif //_E_WINDOW_H_
