#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<deque>
#include<list>
#include<vector>
#include<fstream>
#include<algorithm>
#include<numeric>
using namespace std;
int main() {
	deque<int> d;
	list<int> l;
	vector<int> v;
	ifstream fin("Contain.txt");
	char type[20];
	int n;
	while (!fin.eof()) {
		fin >> type;
		if (strcmp(type, "deque") == 0) {
			for (int i = 0; i < 6; i++) {
				fin >> n;
				d.push_back(n);
			}
		}
		else if (strcmp(type, "list") == 0) {
			for (int i = 0; i < 9; i++) {
				fin >> n;
				l.push_back(n);
			}
		}
		else if (strcmp(type, "vector") == 0) {
			for (int i = 0; i < 8; i++) {
				fin >> n;
				v.push_back(n);
			}
		}
	}
	cout << "Deque: ";
			for (deque<int>::iterator i = d.begin(); i != d.end(); i++) {
				cout << *i << " ";
			}
			cout << endl;
			cout << "List: ";
			for (list<int>::iterator i = l.begin(); i != l.end(); i++) {
				cout << *i << " ";
			}
			cout << endl;
			cout << "Vector: ";
			for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
				cout << *i << " ";
			}
			cout << endl;
			cout << "Enter the selective number: ";
			int inp;
			cin >> inp;
			int am1 = count(d.begin(), d.end(), inp) + count(l.begin(), l.end(), inp) + count(v.begin(), v.end(), inp);
			cout <<"1.The amount of "<<inp<<"'s = "<<am1<< endl;
			int am2 = count_if(d.begin(), d.end(), [inp](auto&i) {return i < inp; }) + count_if(l.begin(), l.end(), [inp](auto&i) {return i < inp; }) + count_if(v.begin(), v.end(), [inp](auto&i) {return i < inp; });
			cout <<"2.The amount of numbers less than "<<inp<<" = "<<am2<< endl;
			int am3 = d.size() + l.size() + v.size();
			cout << "3.The amount of elements = " << am3 << endl;
			int am4 = 0;
			am4 = accumulate(d.begin(), d.end(), am4)+accumulate(l.begin(), l.end(), am4)+accumulate(v.begin(), v.end(), am4);
			cout << "4.The summ of elements = " << am4 << endl;
			double am5 = ((double)am4 / (double)am3);
			cout << "5.The arithmetical mean = " << am5 << endl;
			system("pause");
			return 0;
		}
	

