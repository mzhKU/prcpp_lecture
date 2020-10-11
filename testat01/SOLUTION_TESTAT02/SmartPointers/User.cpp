#include <memory>
#include "Header.h"
#include <string>
#include <iostream>

struct User {
	std::shared_ptr<Object> obj;
	std::string name;
	User(std::string n) : name{ n } {}
	~User() { std::cout << "Name = " << name << std::endl; }
};