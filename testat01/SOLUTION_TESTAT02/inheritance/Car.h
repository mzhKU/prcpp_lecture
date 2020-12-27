#pragma once

#include "Vehicle.h"

class Car : public Vehicle {
	int m_speed;
public:
	Car(size_t mass, int speed);
	void setSpeed(int speed);
	int speed() const;
};