
#include <iostream>
#include "Vector.hpp"
#include "Expression.hpp"

using namespace std;

int main()
{
	using V4 = Vector<double, 4>;
	cout << "IN TESTAT MAIN." << endl;
	V4 A({ 1, 2, 3, 4 });
	V4 B({ 2, 1, 0, 1 });
	Vector<double, 4> D;
	
	auto e = (A - B) * (A + B);
	D = e;
	cout << D << endl;

	B = { 3, 0, 2, 5 };
	cout << e << endl; // [-8,4,5,-9]
	B = { 4, 3, 3, -2 };
	cout << e[1] << endl;


}
