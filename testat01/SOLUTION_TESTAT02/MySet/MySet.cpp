// MySet.cpp : Defines the functions for the static library.
//

#include "MySet.h"
#include <initializer_list>
#include <string>

#include <iostream>
using namespace std;


// ------------------------------------------------------
// CONSTRUCTOR & DESTRUCTOR DEFINITIONS
// ------------------------------------------------------

// Default constructor representing empty set
Set::Set() :
	m_size{ 0 },
	m_capacity{ 0 },
	m_values{ nullptr }
{
	cout << "Default constructor." << endl;
}

// 'capacity': maximal size
Set::Set(size_t capacity) :
	m_values{ make_unique<int[]>(capacity) },
	m_size{ 0 },
	m_capacity{ capacity }
{
	cout << "Private constructor." << endl;
}

// Flat copy constructor (Folie 4-23)
Set::Set(const Set& templateSet) :
	m_values{ templateSet.m_values },
	m_size{   templateSet.m_size }
{
	cout << "Copy constructor." << endl;
}

// Type conversion constructor
// Increment size only when adding an element.
Set::Set(const initializer_list<int>& vs) :
	Set(vs.size()) 
{
	cout << "Initializer list." << endl;
	for (auto& v : vs) {
		if (!this->contains(v)) {
			m_values[m_size] = v;
			m_size++;
		}
	}
}

// Destructor
Set::~Set() {
	cout << "Clearing object." << endl;
	// Other stuff needed? I dont think so because I am
	// using unique_ptr which handles destruction for me.
	// Maybe I don't even need a destructor at all?
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

bool Set::contains(int e) const
{
	int i = 0;
	while(i < m_size) {
		if (*(begin()+i) == e) {
			return true;
		}
		i++;
	}
	return false;
}

bool Set::containsAll(const Set& set) const
{
	for (int i = 0; i < set.size(); i++) {
		if (!(this->contains(  *(set.begin()+i)))) {
			return false;
		}
	}
	return true;
}

bool Set::isEmpty() const
{
	return m_size == 0;
}

size_t Set::size() const
{
	return m_size;
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
	// Hat 'result' u.U. nicht leere Plätze?
}

// 'this' is set2
Set Set::difference(const Set& set) const
{
	size_t differenceCapacity = 0;
	for (int i = 0; i < set.size(); i++) {
		if (!this->contains(*(set.begin() + i))) {
			differenceCapacity++;
		}
	}
	Set difference(differenceCapacity);
	size_t differenceIndex = 0;
	for (int i = 0; i < set.size(); i++) {
		if (!this->contains(*(set.begin() + i))) {
			difference[differenceIndex] = *(set.begin() + i);
			differenceIndex++;
			difference.m_size++;
		}
	}
	return difference;
}

Set Set::intersection(const Set& set) const
{
	// 1) Figure out how big the result set must be
	// 2) Find all elements in both sets and add to result.
	int resultCapacity = 0;
	for (int i = 0; i < size(); i++) {
		if (set.contains(*(begin() + i))) {
			resultCapacity++;
		}
	}
	Set result(resultCapacity);
	size_t resultIndex = 0;
	for (int i = 0; i < size(); i++) {
		if (set.contains(*(begin() + i))) {
			result[resultIndex] = *(begin()+i);
			resultIndex++;
			result.m_size++;
		}
	}
	return result;
}
// ----------------------------------------------------------