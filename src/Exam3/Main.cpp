#include<iostream>
#include<string>
#include<sstream>

#include "EApp.h"
#include "EWindow.h"
#include "ELabel.h"
#include "EButton.h"
#include "ETextEdit.h"
#include "EPanel.h"
#include "ECheckBox.h"


using namespace std;

EApp *app = EApp::getInstance();

void operation(string s) {
	EControl *control = NULL;
	if(s == "App") {
		control = app;
	}else {
		control = app->get(s);
	}
	control->show();
}

void remove(string s1) {
	app -> removeComponent(s1);
}

void add(string s1,string s2) {
	EComponent *component = NULL;
	if (s1[0] == 'W') {
		component = new EWindow(s1);
	}
	else if (s1[0] == 'L') {
		component = new ELabel(s1);
	}
	else if (s1[0] == 'B') {
		component = new EButton(s1);
	}
	else if (s1[0] == 'C') {
		component = new ECheckBox(s1);
	}
	else if (s1[0] == 'P') {
		component = new EPanel(s1);
	}
	else if (s1[0] == 'T') {
		component = new ETextEdit(s1);
	}
	EContainer *container = NULL;
	if (s2[0] == 'A') {
		container = app;
	}
	else if (s2[0] == 'W') {
		container = (EContainer*)(app -> get(s2));
	}
	else if (s2[0] == 'P') {
		container = (EContainer*)(app -> get(s2));
	}
	container->addComponent(component);
}

void readAndDo() {
	int num;
	cin >> num;
	string s1;
	string s2;
	char c;
	for (int i = 0; i < num; i++) {
		cin >> c;
		cin >> s1;
		if(c == '+') {
			cin >> s2;
			add(s1,s2);
		}else {
			remove(s1);
		}
	}
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> s1;
		operation(s1);
	}
	cin >> num;
	if (num == -1) {
		return;
	}
}

int main() {
	readAndDo();
}
