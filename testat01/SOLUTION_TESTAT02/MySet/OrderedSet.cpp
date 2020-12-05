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
	OrderedSet result(*this);
	result.m_size = size() - toSubtract;
	return result;
	// return OrderedSet(begin(), size()-(toSubtract));
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
	/*
	// Hmmm..
	OrderedSet result(*this);
	result.m_start = toSubtract;
	result.m_size = m_size - toSubtract -1;
	return result;
	*/
	return OrderedSet(begin()+toSubtract, m_size-toSubtract);
	// m_size-i : That many elements are left.
}

Set OrderedSet::merge(const Set& set) const
{
	const OrderedSet* os = dynamic_cast<const OrderedSet*>(&set);

	if (size() == 0) { return *os; }
	if (os->size() == 0) { return *this; }

	if (os) {
		cout << "Merging two ordered sets." << endl;

		// Initial index of first subarray
		int i = 0;

		// Initial index of second subarray
		int j = 0;

		int valueToPlaceInResult;
		int iValue;
		int jValue;

		OrderedSet result(size() + os->size());

		// https://www.geeksforgeeks.org/merge-sort/ & help from a friend
		while (i < size() || j < os->size()) {
			iValue = begin()[i];
			jValue = os->begin()[j];
			if (i < size() && j < os->size()) {
				if (iValue <= jValue) {
					valueToPlaceInResult = iValue;
					i++;
				}
				if (iValue >= jValue) {
					valueToPlaceInResult = jValue;
					j++;
				}
			}
			else if (j < os->size()) {
				valueToPlaceInResult = jValue;
				j++;
			}
			else if (i < size()) {
				valueToPlaceInResult = iValue;
				i++;
			}
			result[result.m_size] = valueToPlaceInResult;
			result.m_size++;
		}
		return result;
	}

	return Set::merge(set);
}