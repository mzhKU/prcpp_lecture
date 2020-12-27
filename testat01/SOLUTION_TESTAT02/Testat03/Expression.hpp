#pragma once
#include "Add.hpp"
#include "Subtract.hpp"
#include "Multiply.hpp"
#include "Divide.hpp"

template<typename Left, typename Op, typename Right>
class Expression {
	const Left&  m_left;
	const Right& m_right;
public:
	using value_type = typename Left::value_type;

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r }
	{}
	
	size_t size() const {
		return m_left.size();
	}

	value_type operator[](size_t i) const {
		return Op::template apply<value_type>(m_left[i], m_right[i]);
	}

	friend std::ostream& operator<<(std::ostream& os, const Expression& e) {
		os << '[';
		if (e.size() > 0) { os << e[0]; }
		for (int i = 1; i < e.size(); i++) {
			os << ',' << e[i];
		}
		return os << ']';
	}

	template<typename E>
	bool operator==(const E& e) {
		for (int i = 0; i < e.size(); i++) {
			if ((*this)[i] != e[i]) {
				return false;
			}
		}
		return true;
	}
};


// Left is a scalar.
template<typename Op, typename Right>
class Expression<typename Right::value_type, Op, Right> {
	const typename Right::value_type& m_left;
	const Right& m_right;
public:

	// The expression value type is given by type of Right.
	using value_type = typename Right::value_type;

	Expression(const value_type& l, const Right& r) : m_left{ l }, m_right { r }
	{}

	size_t size() const {
		return m_right.size();
	}

	value_type operator[](size_t i) const {
		return Op::template apply<value_type>(m_left, m_right[i]);
	}

	friend std::ostream& operator<<(std::ostream& os, const Expression& e) {
		os << '[';
		if (e.size() > 0) { os << e[0]; }
		for (int i = 1; i < e.size(); i++) {
			os << ',' << e[i];
		}
		return os << ']';
	}

	template<typename E>
	bool operator==(const E& e) {
		for (int i = 0; i < e.size(); i++) {
			if ((*this)[i] != e[i]) {
				return false;
			}
		}
		return true;
	}
};


// Right is a scalar.
template<typename Left, typename Op>
class Expression<Left, Op, typename Left::value_type> {
	const Left& m_left;
	const typename Left::value_type& m_right;
public:

	// The expression value type is given by type of Right.
	using value_type = typename Left::value_type;

	Expression(const Left& l, const value_type& r) : m_left{ l }, m_right{ r }
	{}

	size_t size() const {
		return m_left.size();
	}

	value_type operator[](size_t i) const {
		return Op::template apply<value_type>(m_left[i], m_right);
	}

	friend std::ostream& operator<<(std::ostream& os, const Expression& e) {
		os << '[';
		if (e.size() > 0) { os << e[0]; }
		for (int i = 1; i < e.size(); i++) {
			os << ',' << e[i];
		}
		return os << ']';
	}

	template<typename E>
	bool operator==(const E& e) {
		for (int i = 0; i < e.size(); i++) {
			if ((*this)[i] != e[i]) {
				return false;
			}
		}
		return true;
	}
};


template<typename Left, typename Right>
Expression<Left, Add, Right> operator+(const Left& l, const Right& r) {
	return Expression<Left, Add, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Subtract, Right> operator-(const Left& l, const Right& r) {
	return Expression<Left, Subtract, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Multiply, Right> operator*(const Left& l, const Right& r) {
	return Expression<Left, Multiply, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Divide, Right> operator/(const Left& l, const Right& r) {
	return Expression<Left, Divide, Right>(l, r);
}