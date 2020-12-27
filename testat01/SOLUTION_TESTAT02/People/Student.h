#pragma once

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Student : public Person {
	int m_number;
public:
	Student(const string& name, int number) :
		Person(name),
		m_number{ number }
	{
		cout << "ctor of Student" << endl;
	}

	// When using 'override', then the base class method MUST be virtual.
	// Virtual MUST be in the base class, if it is here, then it doesn't help.
	void print() override {
		cout << m_name << ", " << m_number << endl;
	}
};