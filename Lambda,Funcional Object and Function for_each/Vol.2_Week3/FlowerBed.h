#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<fstream>
#include<list>
#include<map>
#include<vector>
#include<set>
#include<string>
using namespace std;
class FlowerBed {
private:
	int number;
	string shape;
	vector<string>flowers;
public:
	FlowerBed();
	FlowerBed(int n,string s,vector<string>f);
	FlowerBed(const FlowerBed &f);
	FlowerBed &operator=(FlowerBed &f);
	friend ostream &operator<<(ostream&os, FlowerBed&f);
	bool operator<(FlowerBed f);
	string Shape();
	int Number();
	int Number_of_Flowers();
	int Max();
	~FlowerBed();







};