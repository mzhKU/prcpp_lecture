// MySet.cpp : Defines the functions for the static library.
//

#include "framework.h"
#include "MySet.h"
#include <initializer_list>
#include <string>

#include <iostream>
using namespace std;


// ------------------------------------------------------
// CONSTRUCTOR & DESTRUCTOR DEFINITIONS
// ------------------------------------------------------

// Default constructor
Set::Set() : m_size{ 0 }  {
}

// 'capacity': maximal size
Set::Set(size_t capacity) : m_values{ make_unique<int[]>(capacity) },
							m_size{ 0 } {
	cout << "Private constructor." << endl;
}

// Flat copy constructor (Folie 4-23)
Set::Set(const Set& templateSet) :	m_values{ templateSet.m_values },
									m_size{   templateSet.m_size } {
	cout << "Copy constructor is called." << endl;
}

// Type conversion constructor
Set::Set(initializer_list<int> vals) :
	m_size{ vals.size() },
	m_values{ std::make_shared<int[]>(vals.size()) } {
	int i = 0;
	for (auto v : vals) {
		//  if (!m_values[i].contains(v)) {
		m_values[i] = v;
		// }
		i++;
	}
}

// Destructor
Set::~Set() {
	cout << "Clearing object." << endl;
	// Other stuff needed? I dont think so because I am
	// using unique_ptr which handles destruction for me.
}
// ------------------------------------------------------


// ----------------------------------------------------------
// OBJECT FUNCTIONS
// ----------------------------------------------------------
int* Set::begin() const {
	if (&m_values[0] != nullptr) {
		return m_values.get();
	}
	return nullptr;
}

int Set::operator[](size_t i) const {
	return *(begin() + i);
}

int& Set::operator[](size_t i) {
	return *(begin() + i);
}

bool contains(Set& set) {
	cout << "[WARNING] STUB CONTAINS IMPLEMENTATION." << endl;
	return true;
}

Set Set::merge(const Set& set) const {
	// Erstelle eine neue Menge mit allen Elementen von this.
	Set result(m_size + set.m_size);
	std::copy_n(begin(), m_size, result.begin());
	result.m_size = m_size;

	// Fuege nur jene Elemente von set dazu,
	// die in this noch nicht enthalten sind.
	for (size_t i = 0; i < set.m_size; ++i) {
		if (!contains(set[i])) {
			result[result.m_size++] = set[i];
		}
	}
	return result;
}

// ----------------------------------------------------------