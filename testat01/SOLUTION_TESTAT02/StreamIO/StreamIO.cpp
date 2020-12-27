// StreamIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	/*
	constexpr size_t len = 20;
	struct S {
		char m_name[len];
		uint32_t m_flags = 10;
		double m_value;
	} s;
	cout << s.m_flags << endl;
	*/

	int i; string m;
	cin >> i;

	if (cin.good()) {
		cout << "Entered number is = " << i << endl;
	}
	else {
		cin.clear();
		getline(cin, m);
		stringstream ss{ m };
		while (ss.good()) {
			ss >> m;
			cout << '[' << m << "] ";
		}
		cout << endl << "All entries processed." << endl;
	}
}