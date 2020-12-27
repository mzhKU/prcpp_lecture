#pragma once

#include "Person.h"
#include <memory>

class Car
{
	int m_seats;
	
	// Allocate on heap
	char* m_brand;
	char* m_model;

	std::unique_ptr<Person> owner;

	// color enum

public:
	Car();
	Car(const Car& car);
	Car(Car&& car);
};

