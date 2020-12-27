#include "Person.h"
#include <iostream>

using namespace std;


Person::Person() : name{ new char[100]{"DEFAULT"} }
{}

Person::Person(const char* c) : name{ new char[100] }
{
	int i = 0;
	for (const char* l = c; *l != '\0'; l++) {
		name[i] = *l;
		i++;
	}
	name[i] = '\0';
}

Person::Person(const Person& person) : name{ new char[100] }
{
	int i = 0;
	for (const char* l = person.name; *l != '\0'; l++) {
		name[i] = *l;
		i++;
	}
}

Person::~Person()
{
	delete[] name;
}

void Person::print() {
	int i = 0;
	for (const char* c = name; *c != '\0'; c++) {
		cout << *c;
	}
	cout << endl;
}