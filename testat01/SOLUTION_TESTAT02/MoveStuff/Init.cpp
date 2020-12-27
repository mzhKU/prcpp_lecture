
#include <iostream>
#include "Car.h"
#include "Person.h"
#include <memory>

using namespace std;

int main() {

	Person ich("Superman");
	ich.print();

	Person* a = &ich;
	Person* b = move(a);

	cout << "Address in a = " << a << endl;
	cout << "Address in b = " << b << endl;

}