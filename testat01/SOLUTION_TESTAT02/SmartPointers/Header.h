#pragma once

#include <iostream>


struct Object;
struct User {
	std::shared_ptr<Object> obj;
	std::string name;
	User(std::string n) : name{ n } {}
	~User() { std::cout << "Name = " << name << std::endl; }
};

struct Object {
	int val;
	std::shared_ptr<User> owner;
	Object(int v) : val{ v } {};
	~Object() { std::cout << "Val = " << val << std::endl; }
};



void unique_test();