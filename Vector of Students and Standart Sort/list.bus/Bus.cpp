#include "Bus.h"

Bus::Bus()
{
	route = 0;
	driver = new char[8];
	strcpy(driver,"Unknown");
	number = new char[8];
	strcpy(number, "Unknown");
	busbrand = new char[8];
	strcpy(busbrand, "Unknown");

}

Bus::Bus(int r, char * d, char * n, char * b)
{
	route = r;
	delete[]driver;
	driver = new char[strlen(d)+1];
	strcpy(driver,d);
	delete[]number;
	number = new char[strlen(n)+1];
	strcpy(number,n);
	delete[]busbrand;
	busbrand = new char[strlen(b)+1];
	strcpy(busbrand,b);
}

Bus::Bus(const Bus & b)
{
	route = b.route;
	driver = new char[strlen(b.driver) + 1];
	strcpy(driver, b.driver);
	number = new char[strlen(b.number) + 1];
	strcpy(number, b.number);
	busbrand = new char[strlen(b.busbrand) + 1];
	strcpy(busbrand, b.busbrand);
}

bool  Bus::operator<(Bus & b)
{
	if (route < b.route) return true;
	else return false;
}

bool Bus::operator>(Bus & b)
{
	if (route > b.route) return true;
	else return false;
}

bool Bus::operator==(Bus & b)
{
	if (route == b.route) return true;
	else return false;
}

char* Bus::Number()
{
	return (this->number);
}

char * Bus::Busbrand()
{
	return busbrand;
}

int Bus::Route()
{
	return route;
}

char * Bus::Driver()
{
	return driver;
}

void Bus::Change_Driver(char * b)
{
	delete[]driver;
	driver = new char[strlen(b) + 1];
	strcpy(driver, b);
}

void Bus::Change_Number(char * b)
{
	delete[]number;
	number = new char[strlen(b) + 1];
	strcpy(number, b);
}

Bus::~Bus()
{
	delete[]driver;
	delete[]number;
	delete[]busbrand;
}

ostream & operator<<(ostream & os, Bus & b)
{
	return os << "Bus route: " << b.route << " | " << "Driver's surname: " << b.driver << " | " << "Bus number: " << b.number << " | " << "Bus brand: " << b.busbrand<<" | " << endl;
}
