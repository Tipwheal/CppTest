#ifndef _E_CONTROL_H_
#define _E_CONTROL_H_

class EControl {
public:
	virtual void show() = 0;
	virtual bool containable(){return false;}
	virtual bool isContainer(){return false;}
	virtual std::string getName() = 0;
};

#endif //_E_CONTROL_H_
