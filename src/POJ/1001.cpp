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
	int left;
	int right;
	int times;
	Input(int *data,int a,int b,int c):data(data),left(a),right(b),times(c){}
};

//do input is ok
Input doInput() {
	int *left = new int[7];
	for(int i = 0;i<7;i++) {
		left[i] = -1;
	}
	int ptr = 0;
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
	int times;
	cin >> times;
	int right = 0;
	if(leftLength != 6) {
		right = 5 - leftLength;
	}
	return Input(left,leftLength,5 - leftLength,times);
}

//i should learn gdb,fuck...
//data 12345
//result 12345
//tmp 00000
//recordLength 0
//p data
//q result
//cur 0
//add 0
//total 1
//add 0
//tmp 1
//recordLength 1
//q result+1
//cur 1
//total 2
//tmp 12
//add 0
//recordLength 2
//q result+2
//cur 2
//total 3
//tmp 123
//add 0
//recordLength 3
//q result+3
//cur 3
//total 4
//tmp 1234
//add 0
//recordLength 4
//q result+4
//cur 4
//total 5
//tmp 12345
//add 0
//recordLength 5
//q result+5
//p data+1
//q result
//cur 1
//total 2
//add 0
//tmp 14345
//ptr tmp+1
//q result + 1
//cur 2
//total 4
//add 0
//tmp 14745
//ptr tmp+2
//q result + 2
//cur 3
//total 6
//add 0
//tmp 147(10)5
//ptr tmp+3
//tmp 14705
//tmp 14706
//q result + 3;
//cur 4
//total 8
//add 0
//tmp 1470(14)
//ptr tmp+4
//tmp 14704
//tmp 147041
//recordLength 6
//q result + 4

//data 12345-1
//result 12345-1
//recordLength 7
//tmp 1470411
//p data+2
//add 0
//q result+5
//cur 6
//total 10
//ptr tmp+5


void calcForOneTime(int *data,int *result) {
	int recordLength = 0;
	int *tmp = new int[10000];
	for(int *p = data;*p != -1;p++) {
		int add = 0;//daozheli
		int *q;
		for(q = result;*q!= -1;q++) {
			int cur = (p - data) + (q - result);
			int total = p[0]*q[0] + add;
			add = total / 10;
			if(cur >= recordLength) {
				tmp[cur] = total%10;
				recordLength = cur + 1;
			}else {
				tmp[cur] += total%10;
				int *ptr = &tmp[cur];
				while(*ptr >= 10) {
					ptr[0] -= 10;
					if(&ptr[1] >= tmp + recordLength) {
						ptr[1] = 1;
						recordLength++;
					}else {
						ptr[1] += 1;
					}
					ptr++;
				}
			}
		}
		if(add > 0) {
			int cur = (p - data) + (q - result);
			if(cur >= recordLength) {
				tmp[cur] = add;
				recordLength++;
			}else {
				tmp[cur] += add;
				int *ptr = &tmp[cur];
				while(*ptr >= 10) {
					ptr[0] -= 10;
					if(&ptr[1] >= tmp + recordLength) {
						ptr[1] = 1;
						recordLength++;
					}else {
						ptr[1] += 1;
					}
					ptr++;
				}
			}
		}
	}
	for(int i = 0;i<recordLength;i++) {
		result[i] = tmp[i];
	}
	result[recordLength] = -1;
	delete tmp;
}

//zero 1
//1 reverse input
//>1 multiply

//now
//1 -1
//1.2345
//point to 5
//result should be 54321


//redo later
int main() {
	//Input input = doInput(); //do this later
	int *data = new int[6]{1,2,3,4,5,-1};
	int *result = new int[10000]{1,2,3,4,5,-1};
	calcForOneTime(data,result);
	for(int *p = result;*p != -1;p++) {
		cout << *p;
	}
}
