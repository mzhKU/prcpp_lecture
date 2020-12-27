#include "C.h"

#include <iostream>
using namespace std;

C::C() {}

C::C(char value) : value{ value } {
	cout << "Standard constructor." << endl;
}

C::C(const C& c) {
	cout << "Copy constructor." << endl;
}

/*
C& C::operator=(const C& c) {
	cout << "Address of reference argument: &c = " << &c << endl;      // 
	cout << "Address of this: &*this =           " << &*this << endl;  //
	value = c.value;
	return *this;
}
*/