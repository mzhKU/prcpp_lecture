#pragma once

#include "MySet.h"

class OrderedSet : public Set {
protected:
	size_t m_start;

	int* begin() const override;

public:
	// ------------------------------------------------------
	// CONSTRUCTOR & DESTRUCTOR DECLARATIONS
	// ------------------------------------------------------
	// Standard constructor for empty set
	OrderedSet();

	// Flat copy constructor (Folie 4-23)
	OrderedSet(const OrderedSet& s);

	// Type conversion constructor
	OrderedSet(const initializer_list<int>& vs);

	// Values 
	OrderedSet(const int* vs, size_t size);

	// Destructor
	~OrderedSet();
	// ------------------------------------------------------

	// ------------------------------------------------------
	// INSTANCE METHODS
	// Set merge(const Set& set) const;
	OrderedSet getSmaller(int x) const;
	OrderedSet getLarger(int x) const;
	// ------------------------------------------------------
};