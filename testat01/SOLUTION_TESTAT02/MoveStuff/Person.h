#pragma once
class Person
{
public:

	void print();

	char* name;
	Person();
	Person(const char*);
	Person(const Person& person);
	~Person();
};

