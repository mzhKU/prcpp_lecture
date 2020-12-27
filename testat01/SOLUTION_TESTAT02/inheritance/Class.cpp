
#include <iostream>
#include "Class.h"
#include "Interface.h"
#include <memory>

Class::Class(std::string name) {
	std::cout << "Class constructor" << std::endl;
	m_privateName = name;
}

Class::~Class() {
	std::cout << "Class destructor" << std::endl;
}

void Class::describe() {
	std::cout << "I'm Class [" << m_privateName << "]" << std::endl;
}
