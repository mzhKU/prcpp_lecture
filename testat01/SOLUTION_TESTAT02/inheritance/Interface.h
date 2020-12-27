#pragma once

#include <iostream>
using namespace std;

class Interface {
public:
	virtual ~Interface() { cout << "Destructor interface" << endl; }
	virtual void describe() = 0;
};