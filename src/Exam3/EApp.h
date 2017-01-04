#ifndef _E_APP_H_
#define _E_APP_H_

#include "EContainer.h"
#include<iostream>

using namespace std;

class EApp:public EContainer {
	string name;
	EApp():name("App"){}
	static EApp *instance;
public:
	static EApp *getInstance();
	string getName();
};

string EApp::getName() {
	return name;
}

EApp* EApp::instance = NULL;

EApp *EApp::getInstance() {
	if (instance == NULL) {
		instance = new EApp();
	}
	return instance;
}

#endif //_E_APP_H_
