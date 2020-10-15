// MySet.cpp : Defines the functions for the static library.
//

#include "framework.h"
#include "MySet.h"
#include <initializer_list>

#include <iostream>
using namespace std;


// ------------------------------------------------------
// CONSTRUCTOR & DESTRUCTOR DEFINITIONS
// ------------------------------------------------------

// Default constructor
Set::Set() : m_size{ 0 }  {
}

// 'capacity': maximal size
Set::Set(size_t capacity) : m_values{ make_unique<int[]>(capacity) }, m_size{ 0 } {
	cout << "Private constructor." << endl;
}

// Flat copy constructor (Folie 4-23)
Set::Set(const Set& templateSet) :	m_values{ templateSet.m_values },
									m_size{   templateSet.m_size }
{
	cout << "Copy constructor is called." << endl;
}

// Type conversion constructor
Set::Set(initializer_list<int> vals) : m_size{ sizeof(vals) } {
	auto newSet = Set::Set(sizeof(vals) / sizeof(int));
}

// Destructor
Set::~Set() {
	cout << "Clearing object." << endl;
}
// ------------------------------------------------------


// ----------------------------------------------------------
// OBJECT FUNCTIONS
// ----------------------------------------------------------
Set& Set::operator=(const Set& s) {
	const size_t m_size = s.m_size;
	unique_ptr<int[]> m_values = make_unique<int[]>(s.m_size);
	return *this;
}
// ----------------------------------------------------------

// ------------------------------------------------------
// RUN
// ------------------------------------------------------
int main() {
	// Test default constructor.
	Set defaultSet{};
	Set capacityGivenSet{ 10 };
	Set setUsingConversionConstructor{ 1, 2, 3 };
}
// ------------------------------------------------------