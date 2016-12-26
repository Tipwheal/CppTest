#include<iostream>
#include<sstream>

//std::bind
//std::function
//linklist
//queue

using namespace std;

class ConvertHelper {
public:
	template<typename out_type,typename in_value>
	out_type convert(const in_value t) {
		stringstream stream;
		stream << t;
		out_type result;
		stream >> result;
		return result;
	}
};

int main() {
	string s("3");
	ConvertHelper c;
	int b = 3;
	int a = c.convert<int>(s);
	string d = c.convert<string>(b);
	cout << a << endl << d;
}
