#pragma once

struct User {
	std::shared_ptr<Object> obj;
};

struct Object {
	std::shared_ptr<User> owner;
	int val;
};



void unique_test();