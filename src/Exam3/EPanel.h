#ifndef _E_PANEL_H_
#define _E_PANEL_H_

#include "EContainer.h"
#include "EComponent.h"

using namespace std;

class EPanel:public EContainer,public EComponent{
	string name;
public:
	EPanel(string name):name(name){}
	string getName();
};

string EPanel::getName() {
	return name;
}

#endif //_E_PANEL_H_
