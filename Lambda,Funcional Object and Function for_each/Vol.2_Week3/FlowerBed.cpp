#include "FlowerBed.h"

FlowerBed::FlowerBed()
{
	number = 0;
	shape = "Unknown";
	flowers[0] = "No flowers at all";
}

FlowerBed::FlowerBed(int n, string s, vector<string> f)
{
	number = n;
	shape = s;
	flowers = f;
}

FlowerBed::FlowerBed(const FlowerBed & f)
{
	number = f.number;
	shape = f.shape;
	flowers = f.flowers;
}

FlowerBed & FlowerBed::operator=(FlowerBed & f)
{
	number = f.number;
	shape = f.shape;
	flowers = f.flowers;
	return *this;
}

bool FlowerBed::operator<(FlowerBed f)
{
  return shape<f.shape;
}

string  FlowerBed::Shape()
{
	return shape;
}

int FlowerBed::Number()
{
	return number;
}

int FlowerBed::Number_of_Flowers()
{
	return flowers.size();
}

int FlowerBed::Max()
{
	int max = 0;
	if (max < number) max = number;
	return max;
}

FlowerBed::~FlowerBed()
{

}

ostream & operator<<(ostream & os, FlowerBed & f)
{
	os << "Flowers: " << endl;
	for (int i = 0; i < f.flowers.size(); i++) {
		os << f.flowers[i] << " ";
	}
	os << "; "<< endl;
	return os << "FlowerBed number: " << f.number << " ; " << "FlowerBed shape: " << f.shape << endl;
}
