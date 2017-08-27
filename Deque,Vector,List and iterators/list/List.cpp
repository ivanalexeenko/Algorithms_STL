#define _CRT_SECURE_NO_WARNINGS_
#include<iostream>
#include<list>
#include<iterator>
#include<string>
#include<fstream>
#include <algorithm>
using namespace std;
int main() {
	ifstream fin("LIST.txt");
	string s;
	list<string>l;
	while (!fin.eof()) {
		fin >> s;
		l.push_back(s);
	}
	cout << "Our list:" << endl;
	for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
		cout << *i <<" ";
	}
	l.sort();
	cout << endl;
	cout << "Our sorted list:" << endl;
	for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	cout << "Enter your selective first letter: ";
	char f;
	cin >> f;
	cout << "Selected word(s): " << endl;
	for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
		if ((*i)[0] == f) {
			cout << *i<<" ";
		};
	}
	cout << endl;
	cout << "Our sorted list without selected word(s): " << endl;
	remove_if(l.begin(), l.end(), [f](auto &i) {return i[0] == f; });
	for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
	cout << *i << " ";
	}
	cout << endl;
	system("pause");
	return 0;

}