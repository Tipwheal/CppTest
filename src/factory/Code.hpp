#ifndef _CODE_H_
#define _CODE_H_
#include<string>

class Code {
public:
	virtual void show() = 0;
};

class CppCode:public Code {
	std::string code;
public:
	CppCode(std::string s);
	void show();
};

class JavaCode:public Code {
	std::string code;
public:
	JavaCode(std::string s);
	void show();
};

#endif //_CODE_H_
