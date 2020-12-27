#pragma once

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	string m_name;
public:
	Person(const string& name) : m_name{ name }
	{
		cout << "ctor of Person: " << m_name << endl;
	}

	virtual void print() {
		cout << m_name << endl;
	}
};