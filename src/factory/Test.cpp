#include<iostream>
#include "Code.hpp"
#include "CodeFactory.hpp"

using namespace std;

int main() {
	CodeFactory *cppFactory = new CppCodeFactory();
	Code *cppCode = cppFactory -> createHelloWorld();
	cppCode -> show();
	delete[] cppCode;
	cppCode = cppFactory -> createWrongCode();
	cppCode -> show();
	delete[] cppCode;
	cppFactory -> createCodeFile();
	delete[] cppFactory;
	CodeFactory *javaFactory = new JavaCodeFactory();
	Code *javaCode = javaFactory -> createHelloWorld();
	javaCode -> show();
	delete[] javaCode;
	javaCode = javaFactory -> createWrongCode();
	javaCode -> show();
	delete[] javaCode;
	javaFactory -> createCodeFile();
	delete[] javaFactory;
}
