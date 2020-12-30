#pragma once

#include <array>
#include "stdlib.h"
#include "Expression.hpp"

using namespace std;

template<typename T, int S>
class Vector : public array<T, S>
{
	T m_data[S];

public:
	Vector() {
		Vector(0);
	}

	Vector(const T& val) {
		for (int i = 0; i < S; i++) {
			m_data[i] = val;
		}
	}

	Vector(const std::initializer_list<T>& data) {
		size_t s = __min(data.size(), S);
		auto it = data.begin();
		for (size_t i = 0; i < s; i++) {
			this->at(i) = *it++;
		}
	}

	// "friend": Ist keine Instanzmethode, somit gibt es kein "this" Objekt,
	//           Zugriff auf private Members (Attribute + Methoden).
	friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
		os << '[';
		if (v.size() > 0) { os << v[0]; }
		for (int i = 1; i < v.size(); i++) {
			os << ',' << v[i];
		}
		return os << ']';
	}

	template<typename Left, typename Op, typename Right>
	Vector& operator=(const Expression<Left, Op, Right>& e) {
		size_t s = __min(e.size(), S);
		for (size_t i = 0; i < s; i++) {
			(*this)[i] = e[i];
		}
		return *this;
	}

	template<typename Right>
	bool operator==(const Right& right) {
		if (right.size() != this->size()) { return false; }
		for (int i = 0; i < this->size(); i++) {
			if ((*this)[i] != right[i]) { return false; }
		}
		return true;
	}

	friend T sum(const Vector<T, S>& v, size_t from=0, size_t to=S) {
		T result = 0;
		for (size_t i = from; i < to; i++) {
			result += v[i];
		}
		return result;
	}
};
