// MySet.cpp : Defines the functions for the static library.

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

// Explicit constructor. 'capacity': maximal size
Set::Set(size_t capacity) :
	m_values{ make_unique<int[]>(capacity) },
	m_size{ 0 },
	m_capacity{ capacity }
{
	cout << "Protected constructor." << endl;
}

// Flat copy constructor (Folie 4-23), i.e. it only
// copies the pointer to the array
Set::Set(const Set& templateSet) :
	m_capacity{ templateSet.m_capacity },
	m_size{ templateSet.m_size },
	m_values{ templateSet.m_values }
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
			*(begin() + m_size) = v;
			m_size++;
		}
	}
}

/*
Set::Set(const int* fromHere, size_t size) :
	Set(size)
{
	for (auto i = 0; i < size; i++) {
		if (!contains(fromHere[i])) {
			m_values[m_size++] = fromHere[i];
		}
	}
	cout << "ctor with size" << endl;
}
*/

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
		if (m_values[i] == e) {		// <-- Variante 1
			return true;
		}
		/*
		if ((*this)[i] == e) {		// <-- Variante 2 besser?
			return true;
		}
		*/

		/*
		if (*(begin()+i) == e) {	// <-- Alte Version
			return true;
		}
		*/
		i++;
	}
	return false;
}

bool Set::containsAll(const Set& set) const
{
	for (int i = 0; i < set.size(); i++) {

		if (!(this->contains(set[i]))) {
			return false;
		}

		/*
		if (!(this->contains(  *(set.begin()+i)))) {
			return false;
		}
		*/
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

Set Set::merge(const Set& set) const
{
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
	size_t differenceCapacity = m_size < set.m_size ? set.m_size : m_size;		// <-- Neue Version
	
	/*
	for (int i = 0; i < set.size(); i++) {										// <-- Alte Version
		if (!this->contains(*(set.begin() + i))) {
			differenceCapacity++;
		}
	}
	*/

	Set difference(differenceCapacity);
	size_t differenceIndex = 0;
	for (int i = 0; i < set.size(); i++) {
		if (!this->contains(set[i])) {
			difference[differenceIndex] = set[i];
			differenceIndex++;
			difference.m_size++;
		}
	}
	return difference;
}

Set Set::intersection(const Set& set) const
{
	// 1) Figure out how big the result set must be
	int resultCapacity = m_size < set.m_size ? m_size : set.m_size;
												// <-- Jetzt kann es aber sein, dass die 
												//	   Intersection capacity grösser als
												//     nötig sein wird. Ist das OK?

	/*
	for (int i = 0; i < size(); i++) {			// <-- Alte Version
		if (set.contains(*(begin() + i))) {
			resultCapacity++;
		}
	}
	*/

	// 2) Find all elements in both sets and add to result.
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

/*
--------------------------------------------------
LOGIC OF INTERSECTION
--------------------------------------------------
Given sets A and B:
A      B                FOUND   SIZE(Intersection)
--------------------------------------------------
l      d, f, b, e, s    NO      0
b      d, f, b, e, s    YES     1
k      d, f, b, e, s    NO      1
e      d, f, b, e, s    YES     2
m      d, f, b, e, s    NO      2
--------------------------------------------------
*/
Set Set::intersection(Set&& set) const {
	if (set.m_values.use_count() == 1) {
		size_t sizeIntersection = 0;
		for (int i = 0; i < set.size(); i++) {
			if (this->contains(set[i])) {
				set[sizeIntersection] = set[i];
				sizeIntersection++;
			}
		}
		set.m_size = sizeIntersection;
		return set;
	}
	// Other set object points on the array.
	return intersection(set);
}

Set Set::difference(Set&& set) const {
	if (set.m_values.use_count() == 1) {
		size_t differenceSize = 0;
		for (int i = 0; i < set.size(); i++) {
			if (!this->contains(set[i])) {
				set[differenceSize] = set[i];
				differenceSize++;
			}
		}
		set.m_size = differenceSize;
		return set;
	}
	return difference(set);
}
// ----------------------------------------------------------