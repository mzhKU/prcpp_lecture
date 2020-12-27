#include "Car.h"
#include "Person.h"
#include <memory>

Car::Car() :
	m_seats{ 4 },
	m_brand{ new char[100] {"BMW"} },
	m_model{ new char[100] {"7er"} },
	owner{ std::make_unique<Person>("DEFAULT") }
{}

Car::Car(const Car& car) :
	m_seats{ car.m_seats },
	m_brand{ car.m_brand },
	m_model{ car.m_model },
	owner{ std::make_unique<Person>("DEFAULT") }
{
	
	int i = 0;
	for (char* c = car.owner->name; *c != '\0'; c++) {
		owner->name[i] = *c;
		i++;
	}
	
}

Car::Car(Car&& car) :
	m_seats{ car.m_seats },
	m_brand{ car.m_brand },
	m_model{ car.m_model }
{}
	