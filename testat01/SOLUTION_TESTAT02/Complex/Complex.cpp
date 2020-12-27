// Complex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
	Complex c1(3, 5);
	Complex c2(4.5, -0.9);
	Complex c3(7);
	Complex c4 = 6;
	
	Complex c5 = c1 + c2;
	Complex c6 = c1 + 7;
	Complex c7 = 7 + c2;
	Complex c8 = operator+(7, c4);

	cout << c7 << endl;

	cout << c7[0] << endl;
	c7[0] = 99;
	cout << c7[0] << endl;


	double d = (double)c1;
	cout << d << endl;

	Complex c9(1, 0);
	c9 += Complex(1, 1);
	c9 += Complex(1, 1);
	c9 += Complex(1, 1);
	(c9 += c9) += c9;
	cout << "[C9] " << c9 << endl;


	Complex c10 = 1._i; // Compiler sollte automatisch Complex(0, 1) machen
	Complex c11 = 1_i;

	cout << c11 << endl;

	Complex c12 = c1 + Complex(1, 1);
}
