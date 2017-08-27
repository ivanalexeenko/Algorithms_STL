#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<algorithm>
#include<fstream>
#include<map>
using namespace std;
class Bus {
private:
	int route;
	char*driver;
	char*number;
	char*busbrand;
public:
	Bus();
	Bus(int r,char*d,char*n,char*b);
	Bus(const Bus&b);
	bool operator<(Bus&b);
	bool operator>(Bus&b);
	bool operator==(Bus&b);
	friend ostream &operator<<(ostream&os,Bus&b);
	char *Number();
	char*Busbrand();
	int Route();
	char *Driver();
	void Change_Driver(char* b);
	void Change_Number(char*b);
	~Bus();
	
};