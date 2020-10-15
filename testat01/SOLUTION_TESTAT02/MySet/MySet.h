#pragma once

#include <iostream>
#include <memory>
#include <initializer_list>


using namespace std;

class Set {
protected:
	// Protected Data Structure (allows inheritance)
	const size_t                  m_size;
	const std::shared_ptr<int[]> m_values;

	// 'capacity': maximal set size
	explicit Set(size_t capacity);


public:

	// ------------------------------------------------------
	// CONSTRUCTOR & DESTRUCTOR DECLARATIONS
	// ------------------------------------------------------
	// Standard constructor for empty set
	Set();

	// Flat copy constructor (Folie 4-23)
	Set(const Set& s);

	// Type conversion constructor
	Set(initializer_list<int> v);

	// Destructor
	~Set();
	// ------------------------------------------------------

	// ------------------------------------------------------
	// OBJECT FUNCTIONS
	// ------------------------------------------------------
	Set& operator=(const Set&);
	// ------------------------------------------------------
};