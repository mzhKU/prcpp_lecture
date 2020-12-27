
#include <memory>
#include "SmartPointers.h"
#include <string>
#include <iostream>


struct User {
	std::shared_ptr<StuffObject> obj;
	std::string name;
	User(std::string n) : name{ n } {}
	~User() { std::cout << "Name = " << name << std::endl; }
};