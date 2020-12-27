// AB_STL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SmartPointer.h"
using namespace std;

int main()
{
	SmartPointer<int> sp1(new int(77));
	SmartPointer<int> sp2(new int(22));
	SmartPointer<int> sp3;

	cout << "Unique = " << boolalpha << sp1.IsUnique() << ", Value = " << *sp1 << endl;
	cout << "Unique = " << boolalpha << sp2.IsUnique() << ", Value = " << *sp2 << endl;
	cout << "Unique = " << boolalpha << sp3.IsUnique() << endl;

	// sp1 und sp4 zeigen auf das Integer Objekt 77.
	SmartPointer<int> sp4(sp1);
	cout << "Unique = " << boolalpha << sp1.IsUnique() << ", Value = " << *sp1 << endl;
	cout << "Unique = " << boolalpha << sp4.IsUnique() << ", Value = " << *sp4 << endl;

	{
		// Im Block ist sp2 nicht der einzige Pointer der auf 22 zeigt, deshalb ist unique false.
		SmartPointer<int> sp5(sp2);
		cout << "In block." << endl;
		cout << "Unique = " << boolalpha << sp2.IsUnique() << ", Value = " << *sp2 << endl;

		// Nach dem Block wird sp5 abgeräumt, dann ist sp2 wieder unique.
	}
	cout << "Out of block." << endl;
	cout << "Unique = " << boolalpha << sp2.IsUnique() << ", Value = " << *sp2 << endl;

	sp1 = sp2;
	sp3 = sp2;
}
