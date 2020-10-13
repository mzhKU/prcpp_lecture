#include <iostream>
#include <vector>

#include "Auto.h"
#include "StringContainer.h"

int main()
{
	// std::string brand = "Subaru";
	const char* brand = "Subaru";
	char model[]      = { "Impresa" };
	Auto subaru{ brand };
	Auto subaru_copy{ subaru };
	
	std::cout << "subaru      = "; subaru.showAddressOfThisCar();
	std::cout << "subaru_copy = ";  subaru_copy.showAddressOfThisCar();

	subaru.swap(&subaru_copy);

	std::cout << "subaru      = "; subaru.showAddressOfThisCar();
	std::cout << "subaru_copy = ";  subaru_copy.showAddressOfThisCar();

	// Auto subaru_copy{ subaru };
	// subaru.swap(&subaru_copy);

	// Auto toyota("Toyota");
	// std::cout << "Number of cars = " << toyota.getNumberOfCars() << std::endl;

	// Call conversion constructor.
	// Auto ford{ "Ford" };

	// Objekte auf Stack mit
	// vereinheitlichter Initialisierung.
	// Auto ferrari{ "ferrari", 100 };
	// Auto porsche{ "porsche", 150 };
	// Auto maserati{ "maserati", 200 };

	/*
	std::vector<Auto> supercars = {
		ferrari, // Is this a copy?
	};
	*/

	// Auto newFerrari{ ferrari };

	// "=": Call copy constructor.
	// Auto copiedFerrari = ferrari;

	// std::cout << copiedFerrari.getCarType() << std::endl;

	// std::cout << "ferrari = ";
	// ferrari.showAddressOfThis();

	// std::cout << "supercars[0] = ";
	// supercars[0].showAddressOfThis();

	// std::cout << "Number of cars = " << ferrari.getNumberOfCars() << std::endl;


}