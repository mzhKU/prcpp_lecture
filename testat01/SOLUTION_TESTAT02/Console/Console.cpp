#include <iostream>
#include "../MySet/MySet.h"

using namespace std;

int main()
{

	// Test default constructor.
	Set defaultSet{};
	// Set capacityGivenSet{ 10 };
	Set setUsingConversionConstructor{ { 1, 2, 3 } };


	Set s1;
	Set s11(s1);

	// Set s2({1, 2, 3});

	// Should be without size argument.
	Set s2({ 1, 2, 3 });
	
	Set s21(s2);
	Set s22 = s2;
}

