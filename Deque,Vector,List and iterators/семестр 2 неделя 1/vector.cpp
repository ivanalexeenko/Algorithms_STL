#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main() {
	vector<char> v;
	const int n = 26;
	for (int i = 0; i < n; i++) {
		v.push_back('a' + i);
	}

	for (vector<char>::iterator i = v.begin(); i != v.end(); i++) {
		cout << *i << ' ';
	}
	cout << endl;
	for (vector<char>::reverse_iterator i = v.rbegin(); i != v.rend(); i++) {
		cout << *i << ' ';
	}




	system("pause");
	return 0;
}