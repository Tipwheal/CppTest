#ifndef _E_COMPONENT_H_
#define _E_COMPONENT_H_

#include "EControl.h"

class EComponent :public virtual EControl{
public:
	virtual std::string getName() = 0;
	virtual bool containable() {return true;}
};

#endif //_E_COMPONENT_H_
