
#include <iostream>
#include "Vector.hpp"
#include "Expression.hpp"

using namespace std;

int main()
{

	cout << "IN TESTAT MAIN." << endl;
	using V4 = Vector<double, 4>;

	V4 A({ 1, 2, 3, 4 });
	V4 B({ 2, 1, 0, 1 });

	auto e = (2.0 * (A - B) / 2.0 + B + 5.0) * (A - 4.0 + 4.0 * B) / 4.0;
	cout << "e = " << e << endl;

	double d = sum(A, 1, 3);
	cout << "d = " << d << endl;
	

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
