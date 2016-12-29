#include "CodeFactory.hpp"
#include "Code.hpp"
#include<iostream>
#include<fstream>

using namespace std;

Code* CppCodeFactory::createHelloWorld() {	
	string s("\
#include<iostream>\n\
\n\
using namespace std;\n\
\n\
int main() {\n\
\tcout << \"hello,world!\" << endl;\n\
}\n\
");
	CppCode *code = new CppCode(s);
	return code;
}

Code* CppCodeFactory::createWrongCode() {
	string s("\
import iostream.*;\n\
\n\
psvm {\n\
\tsout(\"hello,world!\");\n\
}\n\
");
	CppCode *code = new CppCode(s);
	return code;
}

void CppCodeFactory::createCodeFile() {
	ofstream out("HelloWorld.cpp",ios::out);
	string s("\
#include<iostream>\n\
\n\
using namespace std;\n\
\n\
int main() {\n\
\tcout << \"hello,world!\" << endl;\n\
}\n\
");
	out << s;
	out.close();
}

Code* JavaCodeFactory::createHelloWorld() {
	string s("\
Class Main {\n\
\n\
\tpublic static void main(String[] args) {\n\
\t\tSystem.out.println(\"Hello,world\");\n\
\t}\n\
\n\
}\n\
");	
	JavaCode *code = new JavaCode(s);	
	return code;
}

Code* JavaCodeFactory::createWrongCode() {
	string s("\
int main() {\n\
\tsout << \"aaa\";\n\
}\n\
");	
	JavaCode *code = new JavaCode(s);	
	return code;
}

void JavaCodeFactory::createCodeFile() {
	ofstream out("Main.java",ios::out);
	string s("\
Class Main {\n\
\n\
\tpublic static void main(String[] args) {\n\
\t\tSystem.out.println(\"Hello,world\");\n\
\t}\n\
\n\
}\n\
");	
	out << s;
	out.close();
}
