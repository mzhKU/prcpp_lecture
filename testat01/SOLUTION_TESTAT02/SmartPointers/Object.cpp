#include <memory>
#include "Header.h"
#include <string>
#include <iostream>

struct Object {
	int val;
	std::shared_ptr<User> owner;
	Object(int v) : val{ v } {};
	~Object() { std::cout << "Val = " << val << std::endl; }
};