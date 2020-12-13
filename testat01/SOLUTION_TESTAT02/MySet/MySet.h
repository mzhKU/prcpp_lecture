#pragma once

#include <iostream>
#include <memory>
#include <initializer_list>


using namespace std;

class Set {
protected:
	// Protected Data Structure (allows inheritance)
	size_t m_capacity; // Maximal number of elements in Set
	size_t m_size;     // Current number of elements in Set
	shared_ptr<int[]> m_values;

	// 'capacity': maximal set size
	explicit Set(size_t capacity);

	virtual int* begin() const;

	int operator[](size_t i) const;
	int& operator[](size_t i);
	
	virtual Set merge(const Set& set) const;
	Set difference(const Set& set) const;
	Set difference(Set&& set) const;
	Set intersection(const Set& set) const;
	Set intersection(Set&& set) const;

public:

	// ------------------------------------------------------
	// CONSTRUCTOR & DESTRUCTOR DECLARATIONS
	// ------------------------------------------------------
	// Standard constructor for empty set
	Set();

	// Flat copy constructor (Folie 4-23)
	Set(const Set& s);

	// Type conversion constructor
	Set(const initializer_list<int>& vs);

	// For Larger/Smaller subsets
	// Set(const int* fromHere, size_t size);

	// Destructor
	~Set();
	// ------------------------------------------------------

	// ------------------------------------------------------
	// OBJECT FUNCTIONS
	// ------------------------------------------------------
	bool contains(int e) const;
	bool containsAll(const Set& set) const;

	bool isEmpty() const;
	size_t size() const;

	bool operator==(const Set& set) const {
		cout << *this << endl;
		cout << set << endl;
		if (size() == set.size()) {
			if (containsAll(set)) {
				if (set.containsAll(*this)) {
					return true;
				}
				return false;
			}
			return false;
		}
		return false;

		// return size() == set.size() && containsAll(set) && set.containsAll(*this);
	}

	// Ausgabe-Operator für Output-Streams (Inline-Implementation schon gegeben)
	friend ostream& operator<<(ostream& os, const Set& s) {
		const int* const vptr = s.begin();
		os << "{";
		if (!s.isEmpty()) os << vptr[0];
		for (size_t i = 1; i < s.m_size; ++i) { os << ", " << vptr[i]; }
		os << "}";
		return os;
	}
	// ------------------------------------------------------


	// ------------------------------------------------------
	// STATIC METHODS
	// ------------------------------------------------------
	static Set merge(const Set& set1, const Set& set2) {
		return set1.merge(set2);
	}

	static Set difference(const Set& set1, const Set& set2) {
		return set2.difference(set1);
	}

	static Set intersection(const Set& set1, const Set& set2) {
		return set1.intersection(set2);
	}

	// Differenzmenge set1 \ set2
	static Set difference(Set&& set1, const Set& set2) {
		return set2.difference(move(set1));
	}

	static Set difference(Set&& set1, Set&& set2) {
		return set2.difference(move(set1));
	}

	// Schnittmenge
	static Set intersection(const Set& set1, Set&& set2) {
		return set1.intersection(move(set2));
	}
	static Set intersection(Set&& set1, const Set& set2) {
		return set2.intersection(move(set1));
	}
	static Set intersection(Set&& set1, Set&& set2) {
		return set1.intersection(move(set2));
	}
	// ------------------------------------------------------
};

