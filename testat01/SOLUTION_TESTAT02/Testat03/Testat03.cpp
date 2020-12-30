
#include <iostream>
#include "Vector.hpp"
#include "Expression.hpp"

using namespace std;

int main()
{

	cout << "IN TESTAT MAIN." << endl;
	using V5 = Vector<double, 5>;

	V5 A({ 1, 2, 3, 4, 5 });
	cout << sum(2.0*A, 1) << endl;

	
	using VI5 = Vector<int, 3>;
	
	VI5 B({ 1, 2, 3 });
	cout << sum(2 * B) << endl;
	


	/*
	Vector<double, 4> D;

	Expression<Vector<int, 3>, Add, Vector<int, 3>> e3 = Vector<int, 3>{ 1, 2, 3 } + Vector<int, 3>{4, 5, 6};
	cout << "e3 = " << e3 << endl;

	cout << "e3 == e3" << endl;
	cout << (e3 == e3) << endl;

	Expression<Expression<Vector<int, 3>, Add, Vector<int, 3>>, Add, Vector<int, 3>> e33 = e3 + Vector<int, 3>{4, 5, 6};
	cout << "e33 = " << e33 << endl;

	using typeOfE3 = typename Expression<Vector<int, 3>, Add, Vector<int, 3>>;
	Expression<typeOfE3, Add, Vector<int, 3>> e33_2 = e3 + Vector<int, 3>{4, 5, 6};
	cout << "e33_2 = " << e33_2 << endl;

	auto e = (A - B) * (A + B);
	D = e;
	cout << D << endl;

	B = { 3, 0, 2, 5 };
	cout << e << endl; // [-8,4,5,-9]
	B = { 4, 3, 3, -2 };
	cout << e[1] << endl;

	*/
}
