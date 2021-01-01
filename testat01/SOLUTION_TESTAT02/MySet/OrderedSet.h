#pragma once

#include "MySet.h"

class OrderedSet : public Set {
protected:
	size_t m_start;

	int* begin() const override;

	OrderedSet(size_t capacity);

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

	// Destructor
	~OrderedSet();
	// ------------------------------------------------------

	// ------------------------------------------------------
	// INSTANCE METHODS
	Set merge(const Set& set) const override;
	OrderedSet getSmaller(int x) const;
	OrderedSet getLarger(int x) const;
	// ------------------------------------------------------
};