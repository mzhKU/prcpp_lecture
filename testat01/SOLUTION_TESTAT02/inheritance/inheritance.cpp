
#include <iostream>

#include "Vehicle.h"
#include "Car.h"
#include "Interface.h"
#include "Class.h"

using namespace std;

void descriptor(Interface* obj) { obj->describe(); }
void descriptor(shared_ptr<Interface> obj) { obj->describe(); }

int main() {

	/*
	cout << endl << "Class Testing..." << endl;
	Class* p1 = new Class("declared with class");
	descriptor(p1);
	delete p1;
	p1 = nullptr;
	shared_ptr<Class> sp1 = make_shared<Class>("declared with Class");
	descriptor(sp1);
	*/

	// Man möchte dass die Methode des Objektes (also 'Class', nicht Interface) aufgerufen wird.
	cout << endl << "Interface testing..." << endl;
	Interface* p2 = new Class("declared with Class");
	descriptor(p2);
	delete p2;
	p2 = nullptr;
	shared_ptr<Interface> sp2 = make_shared<Class>("declared with Interface");
	descriptor(sp2);

	/*
	cout << endl << "Anonyme object testing..." << endl;
	descriptor(new Class("Not defined"));
	descriptor(make_shared<Class>("Not defined"));
	*/
}