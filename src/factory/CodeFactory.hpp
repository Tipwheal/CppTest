#ifndef _CODE_FACTORY_H_
#define _CODE_FACTORY_H_

#include "Code.hpp"

class CodeFactory {
public:
	virtual Code* createHelloWorld() = 0;
	virtual Code* createWrongCode() = 0;
	virtual void createCodeFile() = 0;
};

class CppCodeFactory : public CodeFactory {
public:
	Code* createHelloWorld();
	Code* createWrongCode();
	void createCodeFile();
};


class JavaCodeFactory : public CodeFactory {
public:
	Code* createHelloWorld();
	Code* createWrongCode();
	void createCodeFile();
};

#endif //_CODE_FACTORY_H_
