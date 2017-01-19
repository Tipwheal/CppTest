#include<iostream>

using namespace std;

//list all status input
//.12345
//1.2345
//123456

//length is 5 or six
//leftLength is 0-6,right length is 0-5
//it depends on if there is a .
//so i should read from 6 times,and store 6 or 5
//so ??
//read,if digit ,store,count left
//if . ,count right?,or i should use -1 to tell where is an end? it's ok
//then i use 7 spaces
//-1is the end
//i should record where left ends

//ok, input finished
//now i can use a pointer and i should do multiply for left and right.

//for left part, i should do it like what i do as i lern math
//multiply from right to left and record result and additional part
//additional part should be record as 0 at first
//i can store the result reversively

//how to do with 0?
//that's about output

//000000*000000
//leftLength is 6
//from right to left
//0*0 = 0and0
//record 000000-1(when finished add this)
//so when I output i should test if right result is zero??
//oh,i can just ignore it;just find where to write .
//for all the part use this and test if it's zero
//1.2345*1.2345
//it's about multiply 12345 and 12345 then write . at the last 8 place.
//if there is an zero ,it's hard to say.
//so I should record result length.use -1 is ok.or record the last place
//then find the place to print .

//beware that there are so many forms
//000000-1 .3 all zero should be 0
//01234000-1 .4 should be 123.4
//12340000-1 .4 should be 1234
//000001234566-1 .7 should be .1234566

//so ?? i should multiply first

//i should use a function to simplify input? just return a pointer to store input and a number to store multiply times

struct Input {
	int *data;
	int right;
	int times;
	Input(int *data,int a,int b):data(data),right(a),times(b){}
};

Input input() {
	int *left = new int[7];
	for(int i = 0;i<7;i++) {
		left[i] = -1;
	}
	//a ............................. to be continue
}

int main() {
	int *left = new int[7];		//left is input number
	for(int i = 0;i<7;i++) {
		left[i] = -1;
	}
	int *ptr = 0;
	char tmp = 0;
	int leftLength = 6;
	for(int i = 0;i<6;i++) {
		cin >> tmp;
		if(isdigit(tmp)) {
			left[ptr++] = tmp - 48;
		}
		if(tmp == '.') {
			leftLength = i;
		}
	}
	delete ptr;
	//
	for(int *p = left;*p != -1;p++) {
		if(p == left + leftLength) cout << ".";
		cout << *p;
	}
}
