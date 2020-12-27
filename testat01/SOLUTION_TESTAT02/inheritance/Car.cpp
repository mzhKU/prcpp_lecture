
#include "Car.h"

Car::Car(size_t mass, int speed) :
	Vehicle(mass), m_speed{ speed }
{}


void Car::setSpeed(int speed) {
	m_speed = speed;
}

int Car::speed() const {
	return m_speed;
}