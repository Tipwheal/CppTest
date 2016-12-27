#include <iostream>
#include <functional>
using namespace std;

void test(int a, char c, float f)
{
	cout << a << endl;
	cout << c << endl;
	cout << f << endl;
}

int main()
{
	//bind函数第一个参数是被bind的函数名
	//后面的是这个函数的参数列表，按顺序来
	//placeholders::_i,表示把被bind的函数的当前的参数的位置塞到bind出来的函数的第i个参数的位置
	auto bindFunc1 = bind(test, placeholders::_1, 'A', 100.1);
	bindFunc1(10);

	cout << "=================================\n";

	auto bindFunc2 = bind(test, placeholders::_2, placeholders::_1, 100.1);
	bindFunc2('B', 10);

	cout << "=================================\n";

	auto bindFunc3 = bind(test, placeholders::_2, placeholders::_3, placeholders::_1);
	bindFunc3(100.1, 30, 'C');

	return 0;
}
