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

OrderedSet::OrderedSet(const OrderedSet& s) :
	Set::Set(s),
	m_start{ m_start }
{
}

OrderedSet::OrderedSet(const initializer_list<int>& vs) :
	Set::Set(vs),
	m_start{ 0 }
{
	int* beg = begin();
	std::sort(beg, beg + m_size);
}

OrderedSet::OrderedSet(const int* vs, size_t size) :
	Set::Set(vs, size),
	m_start{ 0 }
{
}

OrderedSet::~OrderedSet()
{
}

/*
Set Set::merge(const Set& set) const
{
	try {
		const OrderedSet* os = dynamic_cast<const OrderedSet*>(&set);
	}
	catch (bad_cast& e) {
		// If we are here, the typecast was valid
		// and the provided set is an OrderedSet.
		// TODO: merge
		return OrderedSet();
	}

	// The dynamic typecast was not valid
	// and so we return an ordinary set.
	return Set::merge(set);
}
*/

OrderedSet OrderedSet::getSmaller(int x) const
{
	return OrderedSet();
}

OrderedSet OrderedSet::getLarger(int x) const
{
	int i = 0;
	while ((*this)[i] <= x) { i++; }
	return OrderedSet(begin()+i, m_size-i);
}


