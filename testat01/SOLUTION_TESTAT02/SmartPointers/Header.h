#pragma once

#include <iostream>
using namespace std;
class Point {
	int m_x, m_y;
public:
	Point(int x = 0, int y = 0) : m_x{ x }, m_y{ y } {}

	void print() const {
		cout << "(" << m_x << ", " << m_y << ")" << endl;
	}
};


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


