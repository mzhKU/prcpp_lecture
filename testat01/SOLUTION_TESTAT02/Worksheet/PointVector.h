#pragma once

#include <memory>
#include "Point.h"
#include <initializer_list>

using namespace std;

class PointVector {

	std::unique_ptr<Point[]> m_points;

	// Vorzeichenloser 64-bit Integer (Long)
	size_t m_capacity; // Wieviele Objekte können maximal abgespeichert werden.
	size_t m_size;     // Wieviele Objekte befinden sich im Array

	void resize(size_t newCapacity);

public:

	// Standard constructor
	PointVector();

	// Copy constructor
	PointVector(const PointVector& pv);

	// User-defined constructor
	PointVector(const initializer_list<Point>& pts);;

	// Move constructor ('&&' right reference)
	PointVector(PointVector&& pv);

	// Add a point to vector
	void pushBack(const Point& p);

	// Read-only access to point with index 'i'
	Point operator[](size_t i) const;
	
	// Write access to point
	Point& operator[](size_t i);

	PointVector& operator=(const PointVector& pv);

	PointVector& operator=(PointVector&& pv);

	void print() const;
};