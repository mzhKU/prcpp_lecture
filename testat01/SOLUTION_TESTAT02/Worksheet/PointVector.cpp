#include <iostream>
#include "PointVector.h"
#include <cassert>

using namespace std;

// -------------------------------------------------------
// CONSTRUCTORS
PointVector::PointVector() :
	m_capacity{ 10 },
	m_size{ 0 },
	m_points{ make_unique<Point[]>(10) }
{
}

PointVector::PointVector(const PointVector& pv) :
	m_capacity{ pv.m_capacity },
	m_size{ pv.m_size },
	m_points{ make_unique<Point[]>(pv.m_capacity) }
{
	// Tiefe Kopie
	for (size_t i = 0; i < m_size; i++) {
		// Links [] um schreibend zuzugreifen
		// Rechts [] um lesend zuzugreifen
		m_points[i] = pv[i];
	}
}

PointVector::PointVector(const std::initializer_list<Point>& pts) :
	m_size{ pts.size() },
	m_capacity{ pts.size() },
	m_points{ std::make_unique<Point[]>(pts.size()) }
{
	size_t i = 0;
	for (auto& p : pts) {
		m_points[i] = p;
		i++;
	}
}

// Verschiebekonstruktor: move data to 'this'
// 2020_10_19_2_2, 01:09:40ff
// Man möchte dass man einen ganze Point Vector
// verschieben kann.
PointVector::PointVector(PointVector&& pv) :
	m_size{ pv.m_size },
	m_capacity{ pv.m_capacity },
	m_points{ move(pv.m_points) } // 2020_10_26, Video 3, 40:00ff
	                              // Aufruf des Verschiebekonstruktors
{                                 // des Unique Pointers.
	                              // Verschiebekonstruktor von unique_ptr
	                              // verschiebt dann die Daten.
	                              // Ohne 'move' würde ein Kopierkonstruktor
	                              // aufgerufen, den unique_ptr aber gar nicht
	                              // hat.
	// To guarantee that pv is zeroed
	pv.m_capacity = 0;
	pv.m_size = 0;
}
// -------------------------------------------------------



// -------------------------------------------------------
// METHODS
void PointVector::pushBack(const Point& p)
{
	if (m_size == m_capacity) {
		resize(1 + 3 * m_capacity / 2);
	}
	// Ist erforderlich
	assert(m_capacity > m_size);
	m_points[m_size] = p;
	m_size++;
}

// 2020_10_19_2_2, 00:50:40ff
void PointVector::resize(size_t newCapacity)
{
	// New capacity can be larger or smaller than
	// than current capacity.
	m_capacity = newCapacity;
	
	if (newCapacity < m_size) {
		m_size = newCapacity;
	}

	// New array on heap
	auto up = make_unique<Point[]>(m_capacity);

	for (size_t i = 0; i < m_size; i++) {
		up[i] = m_points[i];
	} 

	// Nicht möglich weil unique pointer kein Objekt
	// Zuweisen kann --> Keine Kopie möglich.
	// m_points = up;
	// Erfordert move semantik:
	m_points = move(up);
	// 'move' macht 'up' zu einem tmp. Objekt.
	// --> Es wird keine Kopie der Addresse auf
	//     dem Heap gemacht, sondern der Pointer
	//     wird verschoben, nach 'move' kennt
	//     'up' die Addresse des Objekts nicht mehr.
}
// -------------------------------------------------------



// -------------------------------------------------------
// OPERATORS
// Distinction only by 'const'
Point PointVector::operator[](size_t i) const
{
	return m_points[i];
}

Point& PointVector::operator[](size_t i)
{
	return m_points[i];
}

// ZUweisungsoperator
PointVector& PointVector::operator=(const PointVector& pv)
{
	if (&pv != this) {
		m_capacity = pv.m_capacity;
		m_size = pv.m_size;

		/*
		m_points = move(make_unique<Point[]>(pv.m_capacity));
		for (int i = 0; i < pv.m_size; i++) {
			m_points[i] = pv.m_points[i];
		}
		*/

		// Musterlösung
		// 1) Neues temp. Array auf Heap erzeugen
		// 2) Daten in neues tmp. Array kopieren
		// 3) An m_points zuweisen und freigeben.
		auto up = make_unique<Point[]>(pv.m_capacity);
		for (int i = 0; i < m_size; i++) {
			up[i] = pv[i];
		}
		m_points = move(up);
	}
	return *this;
}

// Verschiebeoperator
// Auf rechter Seite ist temp. Objekt (Rechtsreferenz)
PointVector& PointVector::operator=(PointVector&& pv)
{
	if (&pv != this) {
		m_capacity = pv.m_capacity;
		m_size = pv.m_size;

		// Kein umkopieren der Daten, nur Pointer wird
		// umkopiert
		m_points = move(pv.m_points);

		pv.m_size = 0; pv.m_capacity = 0;

		return *this;
	}
}

void PointVector::print() const {
	cout << "[";
	if (m_size) {
		m_points[0].print();
		cout << ", ";
	}
	for (size_t i = 1; i < m_size; i++) {
		m_points[i].print();
		cout << ", ";
	}
	cout << "]" << endl;
}
// -------------------------------------------------------