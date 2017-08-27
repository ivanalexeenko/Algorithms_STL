#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<fstream>
#include<list>
#include<map>
#include<vector>
#include<set>
#include<string>
#include <functional>
#include "FlowerBed.h"
using namespace std;
class Equal_Shape {
public:
	void operator()(FlowerBed f,string a) {
		if (f.Shape() == a) cout << f;

	}
};
void Shape_Equality(FlowerBed f,string a) {
	if (f.Shape() == a) cout << f;
}
void separator() {
	cout << "///////////////////////////////////////" << endl;
}
int main(){
	vector<FlowerBed>vF;
	ifstream fin("Flowers.txt");
	while (!fin.eof()) {
		int n;
		int am;
		string s,c;
		vector<string>vs;
		fin >> n >> s >> am;
		for (int i = 0; i < am; i++) {
			fin >> c;
			vs.push_back(c);
		}
		FlowerBed *temp = new FlowerBed(n, s, vs);
		vF.push_back(*temp);
		vs.clear();
	}
	cout << "Our vector of FlowerBed: " << endl;
	for (int i = 0; i < vF.size(); i++) {
		cout << vF[i];
		separator();
	}
	system("pause");
	system("cls");
	cout << "Sorted vector(shape): " << endl;
	sort(vF.begin(), vF.end());
	for (int i = 0; i < vF.size(); i++) {
		cout << vF[i];
		separator();
	}
	system("pause");
	system("cls");
	map<string, FlowerBed> mpv;
	for (int i = 0; i < vF.size(); i++) {
		mpv.insert(pair<string,FlowerBed>(vF[i].Shape(),vF[i]));
	}
	cout << "Different FlowerBed shapes:"<<endl;
	for (auto i = mpv.begin(); i != mpv.end(); i++) {
		cout << i->first<<" ";
	}
	cout << ";"<<endl;
	int max = 0;
	for (auto i = mpv.begin(); i != mpv.end(); i++) {
		if (max < i->second.Number_of_Flowers()) max = i->second.Number_of_Flowers();
	}

	map<string,FlowerBed>::iterator p=find_if(mpv.begin(), mpv.end(), [max](pair<string, FlowerBed> i) {return max == (i.second.Number_of_Flowers()); });
	cout << "FlowerBed with maximum amount of flowers ("<<max<<") :" << endl;
	cout << p->second;
	system("pause");
	system("cls");
	cout << "Enter FlowerBed shape: ";
	string Shape_Type;
	cin >> Shape_Type;
	for_each(vF.begin(), vF.end(), [Shape_Type](FlowerBed i) {if (Shape_Type == i.Shape()) cout << i; });	// Lambda;
	system("pause");
	system("cls");
	for_each(vF.begin(), vF.end(),bind(Equal_Shape(),placeholders::_1,Shape_Type));		// Functional object;
	system("pause");
	system("cls");
	for_each(vF.begin(), vF.end(), bind(Shape_Equality, placeholders::_1, Shape_Type));		// Function;
	system("pause");


	return 0;
}