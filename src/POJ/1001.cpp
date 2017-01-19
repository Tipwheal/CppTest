#include<iostream>

using namespace std;

//啊这个也有问题

int main() {
	int *left;
	int *right;
	char tmp = 0;
	int ptr = 0;
	int leftLength = 0;
	for(int i = 0;i<6;i++) {
		cin >> tmp;
		if(isdigit(tmp)) {
			left[ptr++] = tmp - 48;
		}
		if(tmp == '.') {
			right = &left[i];
			leftLength = i;
		}
	}
	for(int *p = left;p < left + 6;p++) {
		if(p == right) cout << ".";
		cout << *p;
	}
}
