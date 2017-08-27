#include "Student.h"

Student::Student()
{
	surname = new char[8];
	strcmp(surname, "Unknown");
	group = 1;
	for (int i = 0; i < 4; i++) {
		marks[i] = 0;
	}
}

Student::Student(char * sur, int gr, int * m)
{
	surname = new char[strlen(sur) + 1];
	strcpy(surname, sur);
	group = gr;
	for (int i = 0; i < 4; i++) {
		marks[i] = m[i];
	}
}

Student::Student(const Student & s)
{
	group = s.group;
	for (int i = 0; i < 4; i++) {
		marks[i] = s.marks[i];
	}
	surname = new char[strlen(s.surname) + 1];
	strcpy(surname, s.surname);

}


bool Student::operator>(Student s)
{
	double sum1 = 0, sum2 = 0;
	for (int i = 0; i < 4; i++) {
		sum1 += marks[i];
		sum2 += s.marks[i];
	}
	if ((double)(sum1 / 4) >(double)(sum2 / 4)) {
		return true;
	}
	else return false;
}

bool Student::operator<(Student s)
{
	double sum1 = 0, sum2 = 0;
	for (int i = 0; i < 4; i++) {
		sum1 += marks[i];
		sum2 += s.marks[i];
	}
	if ((double)(sum1 / 4) <(double)(sum2 / 4)) {
		return true;
	}
	else return false;
}

bool Student::operator==(Student s)
{
	double sum1 = 0, sum2 = 0;
	for (int i = 0; i < 4; i++) {
		sum1 += marks[i];
		sum2 += s.marks[i];
	}
	if ((double)(sum1 / 4) == (double)(sum2 / 4)) {
		return true;
	}
	else return false;
}

bool Student::Bad_Session()
{
	int n=0;
	for (int i = 0; i < 4; i++) {
		if (marks[i] >= 4) {
			n++;
		}
	}
	if (n < 4) return true;
	else return false;
}

int Student::Mark_Summ()
{
	int summ=0;
	for (int i = 0; i < 4; i++) {
		summ += marks[i];
	}
	return summ;
}

Student::~Student(){}


ostream & operator<<(ostream & os, Student & s)
{
	os << "Student's surname: " << s.surname << endl << "Group " << s.group << endl << "Session marks: ";
	for (int i = 0; i < 4; i++) {
		os << s.marks[i] << " ";
	}
	return os << endl;
}


