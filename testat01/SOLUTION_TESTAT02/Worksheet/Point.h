#pragma once


#include <initializer_list>
#include <memory>
#include <exception>

class Point {
	int m_x, m_y;

public:
	Point(int x = 0, int y = 0) : m_x{ x }, m_y{ y } {}
	int getX() const { return m_x; }
	int getY() const { return m_y; }

	void setX(int x) { m_x = x; }
	void setY(int y) { m_y = y; }
	void print() const;

};