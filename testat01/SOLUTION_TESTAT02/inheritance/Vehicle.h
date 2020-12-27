#pragma once
class Vehicle
{
	size_t m_mass;
public:
	Vehicle(size_t mass);
	void setMass(size_t mass);
	size_t mass() const;
};