#include<iostream>
#include "Code.hpp"

using namespace std;

CppCode::CppCode(string s) : code(s) {}

void CppCode::show() {
	cout << "cpp: " << endl;
	cout << code;
}

JavaCode::JavaCode(string s) : code(s) {}

void JavaCode::show() {
	cout << "java: " << endl;
	cout << code;
}
