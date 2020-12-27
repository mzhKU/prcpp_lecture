#pragma once

using namespace std;


class Complex {
	double m_real, m_imag;

public:
	// Durch Default-Wert kann mit dem Konstruktor auch eine reelle
	// Zahl eine Komplexe Zahl erzeugt werden.
	Complex(double real, double imag=0) : m_real{ real }, m_imag{ imag } 
	{}

	friend ostream& operator<<(ostream& os, Complex& c) {
		return os << '[' << c.m_real << ',' << c.m_imag << ']';
	}

	// Nur Lesen
	double operator[](size_t i) const {
		return (i == 0) ? m_real : m_imag;
	}

	// Mit Schreibrechten -> gibt Referenz auf Attribut zurück.
	double& operator[](size_t i) {
		return (i == 0) ? m_real : m_imag;
	}

	// Typkonvertierungsoperator
	explicit operator double() {
		return hypot(m_real, m_imag);
	}

	// friend: Ist keine Instanzmethode --> somit gibt es kein 'this' Objekt hier.
	//         Zugriff auf private Members (Attribute, Methoden)
	// Globaler Operator.
	friend Complex operator+(const Complex& c1, const Complex& c2) {
		return Complex(c1.m_real + c2.m_real, c1.m_imag + c2.m_imag);
	}

	// Operator with Move semantics
	friend Complex&& operator+(const Complex& c1, Complex&& c2) {
		c2 += c1; // Dadurch wird c2 verändert.
		return move(c2);	// Der Speicherplatz von c2 darf zurückgegeben
							// dh. verschoben werden.
	}

	Complex& operator+=(const Complex& c2) {
		this->m_real += c2.m_real;
		this->m_imag += c2.m_imag;
		return *this;
	}

	// Operator als Instanzmethode, kommt nur dann zum Einsatz
	// wenn 'this' vom Typ Complex ist.
	// Verändert 'this' Objekt nicht --> 'const' am Ende.
	/*
	Complex operator + (const Complex& c) const {
		return Complex(m_real + c.m_real, m_imag + c.m_imag);
	}
	*/
};

// Literaloperator für '_i' Suffix
Complex operator"" _i(long double d) {
	return Complex(0, d);
}

// Literaloperator für '_i' Suffix
Complex operator"" _i(unsigned long long d) {
	return Complex(0, d);
}
