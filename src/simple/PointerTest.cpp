#include<iostream>

using namespace std;

int main() {
	int *p = new int[4];
	p[0] = 3;
	p[1] = 4;
	p[2] = 5;
	p[3] = 6;
	cout << p[0] << endl;

	int **q = new int*[2];
	q[0] = p;
	cout << q[0][3] << endl;

	//指针好复杂，我去睡觉吧
}
