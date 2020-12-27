#include "Vehicle.h"

Vehicle::Vehicle(size_t mass) : m_mass{ mass }
{}


void Vehicle::setMass(size_t mass)
{
    m_mass = mass;
}


size_t Vehicle::mass() const
{
    // TODO: Add your implementation code here.
    return m_mass;
}
