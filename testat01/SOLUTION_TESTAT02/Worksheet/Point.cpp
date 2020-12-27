
#include "Point.h"
#include <iostream>

using namespace std;

void Point::print() const
{
	cout << "(" << m_x << ", " << m_y << ")";
}
