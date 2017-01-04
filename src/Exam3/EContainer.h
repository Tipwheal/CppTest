#ifndef _E_CONTAiNER_H_
#define _E_CONTAiNER_H_

#include "EControl.h"
#include "EComponent.h"
#include<vector>

using namespace std;

class EContainer :public virtual EControl{
public:
	vector<EComponent*> list;
	virtual void addComponent(EComponent *component);
	virtual void removeComponent(string name);
	virtual EComponent* get(string name);
	virtual bool isContainer() {return true;}
	virtual void show();
	virtual EContainer* getContainer(string name);
	virtual std::string getName() = 0;
};

void EContainer::addComponent(EComponent *component) {
	list.push_back(component);
}

void EContainer::removeComponent(string name) {
	vector<EComponent*>::iterator it;
	for(it = list.begin();it != list.end();it++) {
		if((*it) -> getName() == name) {
			list.erase(it);
		}
		if((*it) -> isContainer()) {
			EContainer *child = (EContainer*)(*it);
			child -> removeComponent(name);
		}
	}
}

void EContainer::show() {
	vector<EComponent*>::iterator it;
	for(it = list.begin();it != list.end();it++) {
		(*it) -> show();
	}
	cout << this->getName() << endl;
}

EContainer* EContainer::getContainer(string name) {
	if(this -> getName() == name) {
		return this -> isContainer()?(EContainer*)this:NULL;
	}
	vector<EComponent*>::iterator it;
	for(it = list.begin();it != list.end();it++) {
		if((*it) -> getName() == name) {
			return (*it) -> isContainer()?(EContainer*)(*it):NULL;
		}
		if((*it) -> isContainer()) {
			EContainer *child = (EContainer*)(*it);
			EContainer *childGet = child -> getContainer(name);
			if(childGet != NULL) {
				return childGet;
			}
		}
	}
	return NULL;
}

EComponent* EContainer::get(string name) {
	if(this -> getName() == name) {
		if(this -> containable()) {
			return (EComponent*)this;
		}else {
			return NULL;
		}
	}
	vector<EComponent*>::iterator it;
	for(it = list.begin();it != list.end();it ++) {
		if((*it) -> getName() == name) {
			return *it;
		}
		if((*it) -> isContainer()) {
			EContainer *child = (EContainer*)(*it);
			EComponent *childGet = child -> get(name);
			if(childGet != NULL) {
				return childGet;
			}
		}
	}
	return NULL;
}

#endif //_E_CONTAiNER_H_
