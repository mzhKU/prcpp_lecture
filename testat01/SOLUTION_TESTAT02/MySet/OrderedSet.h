#pragma once

#include "MySet.h"

class OrderedSet : public Set {
protected:
	size_t m_start;

	int* begin() const override;
	Set merge(const Set& set) const override;

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

	// Adjusted set (larger, smaller)
	OrderedSet(int* fromHere, size_t size);

	// Destructor
	~OrderedSet();
	// ------------------------------------------------------

	// ------------------------------------------------------
	// INSTANCE METHODS
	OrderedSet getSmaller(int x) const;
	OrderedSet getLarger(int x) const;
	// ------------------------------------------------------
};