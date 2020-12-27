// People.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "Student.h"


int main()
{
	Person* p = new Person("Peter");
	Student* s = new Student("Berta", 123);
	p->print();
	s->print();


	// Polymorphie funktioniert nur mit Pointern oder mit
	// Referenzen, nicht mit Objekten auf dem Stack.
	Person* p1 = new Student("Berta", 123);
	p1->print();

	// Kein Polymorphismus:
	Person p2 = Student("Claudia", 456);
	p2.print(); // gibt nur Name aus.


	// Referenz -> Polymorphie möglich:
	Student s2 = Student("Thomas", 876);
	Person& p3 = s2;
	p3.print(); // Gibt Name + Matrikelnr. aus.
}
