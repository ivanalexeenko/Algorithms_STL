#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
class Student {
public:
	char*surname;
	int group;
	int marks[4];
	Student();
	Student(char*sur, int gr, int*m);
	Student(const Student&s);
	bool operator>(Student s);
	bool operator<(Student s);
	bool operator==(Student s);
	friend ostream &operator<<(ostream &os, Student&s);
	bool Bad_Session();
	int Mark_Summ();
	~Student();
};