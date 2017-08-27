#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<fstream>
#include"Bus.h"
#include<list>
#include<map>
#include<vector>
#include<set>
void separator(){
	cout << "////////////////////////////////////////////////////////////////////////////////////////" << endl;
}
using namespace std;
int main() {
	ifstream fin("Bus.txt");
	int ro;
	char dr[30];
	char nu[30];
	char bu[30];
	Bus*temp;
	list<Bus> lB ;
	while (!fin.eof()) {
		fin >> ro >> dr >> nu >> bu;
		temp = new Bus(ro , dr, nu, bu);
		lB.push_back(*temp);
	}
	for (auto i = lB.begin(); i != lB.end(); i++) {
		cout << *i;
	}
	lB.sort([](auto &it1, auto&it2) {return it1 < it2; });
	separator();
	for (auto i = lB.begin(); i != lB.end(); i++) {
		cout << *i;
	}
	system("pause");
	system("cls");
	/*map<pair<char*, char*>,Bus> m; 
	for (auto i = lB.begin(); i != lB.end(); i++) {
		m.insert(pair < pair<char*, char*>, Bus>(i->Number(), i->Busbrand(), *i));
	}*/
	map<char*,Bus> Conte;
	for (auto i = lB.begin(); i != lB.end(); i++) {
		Conte.insert(pair<char*, Bus>(i->Number(),*i));
	}
	int a = 0;
	int *A = new int[Conte.size()];
	for (map<char*, Bus>::iterator i = Conte.begin(); i != Conte.end(); i++) {
		A[a++] = (*i).second.Route();
	}
	cout << "Unique route(s) is(are):  " << endl;
	int counter = 0;
	for (int i = 0; i < Conte.size(); i++) {
		counter = 0;
		for (int j = 0; j < Conte.size(); j++) {
			if (A[i] == A[j] && i != j) {
				counter++;
			}
		}
		if (counter == 0) {
			cout << A[i] << " ";
		}
	}
	int in;
	cout << endl;
	cout << "Let's find the drivers by bus route(Enter the route): ";
	cin >> in;
	cout << in << "'s route driver(s): " << endl;
	for (auto i = Conte.begin(); i != Conte.end(); i++) {
		if (in==(*i).second.Route()) {
			cout << (*i).second.Driver() << endl;
		}
	}
	char sur1[30];
	char sur2[30];
	cout << "Who's surname do we want to change? - ";
	cin >> sur1;
	cout << "Enter a new surname : ";
	cin >> sur2;
	int b = 0;
	for (auto i = Conte.begin(); i != Conte.end(); i++) {
		if (strcmp(sur1, (*i).second.Driver())==0) { break; }
		else b++;
	}
	int c = 0;
	for (auto i = Conte.begin(); i != Conte.end(); i++) {
		if (c == b) {
			i->second.Change_Driver(sur2);
		}
		c++;
	}
	c = 0;
	cout << "New driver data: " << endl;
	for (auto i = Conte.begin(); i != Conte.end(); i++) {
		if (c == b)
		{
			cout << i->second;
		}
		c++;
	}
	b = 0; c = 0;
	char sur3[30];
	char num[30];
	cout << "Who's bus number do we want to change? - ";
	cin >> sur3;
	cout << "Enter a new number : ";
	cin >>num;
	for (auto i = Conte.begin(); i != Conte.end(); i++) {
		if (strcmp(sur3, i->second.Driver()) == 0) { break; }
		else b++;
	}
	for (auto i = Conte.begin(); i != Conte.end(); i++) {
		if (c == b) {
			i->second.Change_Number(num);
		}
		c++;
	}
	c = 0;
	cout << "New driver data: " << endl;
	for (auto i = Conte.begin(); i != Conte.end(); i++) {
		if (c == b)
		{
			cout << i->second;
		}
		c++;
	}
	cout << "Enter driver's surname: ";
	char *sur=new char[30];
	cin >> sur;
	map<char*, Bus>::iterator iter = find_if(Conte.begin(), Conte.end(), [sur](pair<char*, Bus> i) {return (!strcmp(sur, i.second.Driver())); });
	cout << sur << "'s bus is " << iter->second.Route() << "'s" << endl;
	set<string>sB;
	for (auto i = Conte.begin(); i != Conte.end(); i++) {
		sB.insert((i->second).Busbrand());
	}
	cout << "The amount of unique buses = " << sB.size() - 1 << endl;
	delete[]A;
	delete[] sur;
	system("pause");
	return 0;
}