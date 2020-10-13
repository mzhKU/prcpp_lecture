#include <iostream>
#include <string>
#include "Auto.h"
#include "string.h"


// ----------------------------------------------------------
// PREPROCESSOR DEKLARATIONS
#define NO_MODEL "NO_MODEL"
#define NO_BRAND "NO_BRAND"
#define NEEDED_BYTES strlen(NO_MODEL)+1
// ----------------------------------------------------------


// ----------------------------------------------------------
// STATIC VARIABLES
// ----------------------------------------------------------
unsigned int Auto::carCounter = 0;
// ----------------------------------------------------------


// ----------------------------------------------------------
// CONSTRUCTORS
// ----------------------------------------------------------
// Default constructor
Auto::Auto() : constructionYear{ 0 }, model{ new char[NEEDED_BYTES] }, brand{ NO_BRAND }, thisCarsPS{ 0 } {
	strcpy_s(model, NEEDED_BYTES, NO_MODEL);
	carCounter++;
}

// Constructor with brand
Auto::Auto(const char* brand) : constructionYear{ 0 }, model{ new char[NEEDED_BYTES] }, brand{ brand }, thisCarsPS{ 0 } {
	strcpy_s(model, NEEDED_BYTES, NO_MODEL);
	carCounter++;
}

// Constructor with brand and model
Auto::Auto(std::string brand, const char* m) : brand{ brand }, constructionYear{ 99 }, thisCarsPS{ 0 } {
	model = new char[strlen(m) + 1];
	strcpy_s(model, strlen(model)+1, m);
	carCounter++;
}

// Copy constructor
Auto::Auto(const Auto &templateCar) : brand{ templateCar.brand+"_copy" }, constructionYear{ templateCar.constructionYear }, thisCarsPS{ templateCar.thisCarsPS } {
	size_t neededBytes = strlen(templateCar.model) + 1;
	model = new char[neededBytes];
	strcpy_s(model, neededBytes, templateCar.model);
	carCounter++;
}
// ----------------------------------------------------------


// ----------------------------------------------------------
// DESTRUCTOR
// ----------------------------------------------------------
Auto::~Auto() {
	delete this->model;
	carCounter--;
	std::cout << "Clearing of car " << getCarType() << " finished. " << std::endl;
}
// ----------------------------------------------------------


// ----------------------------------------------------------
// OBJECT FUNCTIONS
// ----------------------------------------------------------
void Auto::swap(Auto* a) {
	Auto tmp = *this;
	*a = *this;
	*this = tmp;
}

Auto& Auto::operator=(const Auto& s) {
	thisCarsPS = s.thisCarsPS;
	brand = s.brand;
	model = new char[strlen(s.model) + 1];
	strcpy_s(model, strlen(s.model) + 1, s.model);
	return *this;
}
// ----------------------------------------------------------


// ----------------------------------------------------------
// UTILITIES
// ----------------------------------------------------------
unsigned int Auto::getNumberOfCars() {
	return carCounter; 
}

void Auto::showAddressOfThisCar() {
	std::cout << "this = " << this << std::endl;
}

const std::string Auto::getCarType() const {
	return brand;
}
void Auto::setCarType(std::string brand) {
	brand = brand;
}

unsigned int Auto::getPS() const {
	return thisCarsPS;
}
void Auto::setPS(unsigned int ps) {
	thisCarsPS = ps;
}
// ----------------------------------------------------------






