#include "OrderedSet.h"
#include <algorithm>

int* OrderedSet::begin() const
{
	// Example:
	// vals = { 6, 9, 20 };
	// m_start = <index 1> (= 9)
	// *(Set::begin()+1) = 9;
	return Set::begin() + m_start;
}


OrderedSet::OrderedSet() :
	// Set(), <- implicit
	m_start{ 0 }
{
}

OrderedSet::OrderedSet(size_t capacity) :
	Set::Set(capacity),
	m_start{ 0 }
{
}

OrderedSet::OrderedSet(const OrderedSet& s) :
	Set::Set(s),
	m_start{ 0 }
{
}

OrderedSet::OrderedSet(const initializer_list<int>& vs) :
	Set::Set(vs),
	m_start{ 0 }
{
	int* beg = begin();
	std::sort(beg, beg + m_size);
}

OrderedSet::OrderedSet(int* fromHere, size_t size) :
	Set(fromHere, size),
	m_start{ 0 }
{
}

OrderedSet::~OrderedSet()
{
}


OrderedSet OrderedSet::getSmaller(int x) const
{
	// Last index position of the array is size-1
	size_t i = size()-1;
	int toSubtract = 0;
	
	// Scan all indeces before 0 to prevent decrementing
	// i below zero.
	while (i > 0) {
		if ((*this)[i] >= x) { toSubtract++; }
		i--;
	}
	// Check position 0.
	if ((*this)[0] >= x) { toSubtract++; }
	return OrderedSet(begin(), size()-(toSubtract));
}

// Adjust pointer to array, m_start, m_size
OrderedSet OrderedSet::getLarger(int x) const
{
	size_t i = 0;
	int toSubtract = 0;
	while (i <= size()-1) {
		if ((*this)[i] <= x) {
			toSubtract++;
		}
		i++;
	}
	return OrderedSet(begin()+toSubtract, m_size-toSubtract);
	// m_size-i : That many elements are left.
}

Set OrderedSet::merge(const Set& set) const
{
	try {
		const OrderedSet* os = dynamic_cast<const OrderedSet*>(&set);
		if (os) {
			cout << "Merging two ordered sets." << endl;
		}
		/*
		lowerA = this.getSmaller(B.begin())
		Merge = lowerA U B
		*/

		// [WIP] Missing some elements when A contains elements larger B
		return Set::merge(getSmaller(*(os->begin())), *os);
	}
	catch (bad_cast& e) {
		// If we are here, the typecast was invalid
		// and the provided set is not an OrderedSet.
		// TODO: merge
		cout << "'set' argument is not ordered set." << endl;
	}

	// The dynamic typecast was not valid
	// and so we return an ordinary set.
	return Set::merge(set);
}