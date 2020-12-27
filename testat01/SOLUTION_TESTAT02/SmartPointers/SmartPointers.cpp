// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Header.h"
#include <memory>

using namespace std;

struct C {

    // Standard constructor
    C() {
        cout << "std ctor" << endl;
    }

    // Copy constructor
    C(const C& c) {
        cout << "copy ctor" << endl;
    }

    // Assignment operator
    C& operator=(const C& c) {
        cout << "assignment" << endl; return *this;
    }
};


C foo() {
    // Return new object by value
    return C();
}


int main()
{

    int stackInteger = 3;
    unique_ptr<int>   uniqueIntegerPointer = std::make_unique<int>(stackInteger);
    unique_ptr<int[]> uniqueArrayPointer   = std::make_unique<int[]>(10);

}