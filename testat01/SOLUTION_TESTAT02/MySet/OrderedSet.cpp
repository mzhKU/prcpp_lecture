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

OrderedSet::OrderedSet(size_t capacity) : Set::Set(capacity), m_start{ 0 } {
}

OrderedSet::OrderedSet(const OrderedSet& s) : Set::Set(s), m_start{ s.m_start } {
}

OrderedSet::OrderedSet(const initializer_list<int>& vs) : Set::Set(vs), m_start{ 0 } {
	int* beg = begin();
	std::sort(beg, beg + m_size);
}

OrderedSet::~OrderedSet() {}

OrderedSet OrderedSet::getSmaller(int x) const {
	for (int64_t i = size()-1; i >= 0; i--) {
		if ((*this)[i] < x) {
			OrderedSet os(*this);
			os.m_start = m_start;
			os.m_size -= (size()-(i+1));
			return os;
		}
	}
	return OrderedSet();
}

OrderedSet OrderedSet::getLarger(int x) const {
	for (size_t i = 0; i < (*this).size(); i++) {
		if ((*this)[i] > x) {
			OrderedSet os(*this);
			os.m_start += i;
			os.m_size = m_size - i;
			return os;
		}
	}
	return OrderedSet();
}

Set OrderedSet::merge(const Set& set) const {
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