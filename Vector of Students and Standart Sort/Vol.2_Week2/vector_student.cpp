#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<fstream>
#include<iostream>
#include<algorithm>
#include "Student.h"
#include<map>

using namespace std;
int main(){
	vector<Student> vS;
	ifstream fin("Student.txt");
	char s[30];
	int g;
	int m[4];
	
	cout << "Our Students: " << endl;
	Student *temp;
	while (!fin.eof()) {
		fin >> s >> g;
		for (int i = 0; i < 4; i++) {
			fin >> m[i];
		}
		temp = new Student(s, g, m);
		vS.push_back(*temp);
	
	}
	for (vector<Student>::iterator i = vS.begin(); i != vS.end(); i++) {
		cout << *i;
	}
	system("pause");
	system("cls");
	sort(vS.begin(), vS.end(), [](auto&i1, auto&i2) {return i1 < i2; });
	cout << "Sorted list of students(average mark): " << endl;
	for (vector<Student>::iterator i = vS.begin(); i != vS.end(); i++) {
		cout << *i;
	}
	system("pause");
	system("cls");
	cout << "Whom do we want to delete? - ";
	char sel[30];
	cin >> sel;
	remove_if(vS.begin(), vS.end(), [&sel](auto &a) {return (!strcmp(sel, a.surname)); });
	cout << "Our list without " << sel << ":" << endl;
	for (vector<Student>::iterator i = vS.begin(); i != vS.end()-1; i++) {
		cout << *i;
	}
	system("pause");
	system("cls");
	map<char*,Student> mp;
	for (int i = 0; i < vS.size(); i++) {
		mp.insert(pair<char*, Student>((vS[i]).surname, vS[i]));
	}
	cout << "Those,who failed (accept for deleted): " << endl;
	for (auto it = mp.begin(); it != mp.end(); it++) {
	if((it->second).Bad_Session()==true){
		cout << it->first << endl;
	}
	}
	cout << "Enter the group: ";
	int input;
	cin >> input;
	cout << "The best in the " << input << "th group is : " << endl;
	vector<Student> helper;
	for (auto i = mp.begin();i!=mp.end(); i++) {
		if (((*i).second).group == input) {
			helper.push_back((*i).second);
		}
	}
	sort(helper.begin(),helper.end(), [](auto&i1, auto&i2) {return i1 < i2; });
	if (helper.empty()) cout << "Nobody" << endl;
	else cout << (*(helper.end() - 1)).surname << endl;

	

	system("pause");
	return 0;
}