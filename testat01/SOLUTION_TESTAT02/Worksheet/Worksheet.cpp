// Worksheet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Point.h"
#include <iostream>
#include "PointVector.h"
#include "string"

#include "Element.h"
#include "ElementCollection.h"

using namespace std;

void createPointer(int*& number, int val) {
	number = new int(val);
}

struct {
	unsigned short character : 8;
	unsigned short color : 4;
} text[80];


union Number {
	struct {
		int num;
		int den;
	} rational;
	double d;
};

enum class Color : uint16_t { R, G, Y, W };


struct Bitformat {
	uint8_t font : 1;
	uint8_t bold : 1;
	uint8_t ital : 1;
	uint8_t subs : 1;
};


union m_format {
	Bitformat bf;
	bool superscript;
	bool bold;
	Color color;
	Color colorBackground;
};

struct Format {
	Color m_color;
	string m_font;
	float m_fontsize;
	Bitformat m_flags;

	Format(string fonttype, float fontsize) :
		m_font{ fonttype },
		m_fontsize{ fontsize }
	{};
};



int main() {


	
	Point p1({ 1, 2 });
	Point p2({ 3, 4 });

	PointVector pv1({ p1, p2 });
	PointVector pv2;

	
	pv1 = pv2;

	pv1.print();
	pv2.print();

	pv1 = PointVector({ p1 });

	PointVector pvMoved(move(pv1));
	

	string first = "hello";
	string second = "world";

	cout << first + " " + second << endl;




	/*

	Format f("Arial", 10);

	int a = 2, b = 9;
	int* pa = &a, *& rpa = pa;
	*rpa = 4; rpa = &b; pa = &a;
	cout << "*rpa = " << *rpa << endl;



	cout << "sizeof(m_format) = " << sizeof(m_format) << endl;


	Color white;

	cout << "sizeof(white) = " << sizeof(white) << endl;

	Bitformat bf = { 1, 0, 0, 0 };
	cout << "sizeof(bf) = " << sizeof(bf) << endl;

	Number n;
	n.rational = { 2, 3 };
	// n.d = 4.3;
	

	cout << "n.d = " << n.d << endl;
	cout << "n.rational.num = " << n.rational.num << endl;


	text[20].character = 'a';
	text[20].color = 5;



	int* ptr = nullptr;
	createPointer(ptr, 5);
	cout << "*ptr = " << *ptr << endl;
	delete ptr;


	int v = 5;
	int* w = &v;
	int* x = &v;



	auto up = make_unique<int[]>(10);
	for (auto i : { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }) {
		up[i] = i + 100;
	}

	cout << "up[3] = " << up[3] << endl;



	Point p1;
	Point p2(3, 5);

	PointVector pv1;             // Standardkonstruktor
	PointVector pv2({ p1, p2 }); // Initialisierungsliste
	PointVector pv3(pv2);        // Tiefe Kopie

	PointVector pv4{ move(pv3) };
	*/

	/*

	pv3[0] = Point(7, 9);
	cout << "here" << endl;
	pv1.print();
	pv2.print();
	pv3.print();

	// Zuweisungsoperator (Kopie Daten von pv2 nach pv1)
	pv1 = pv2;

	// Verschiebeoperator, rechts ist temp. Objekt.
	pv1 = PointVector({ p2 });

	// Verschiebekonstruktor
	PointVector pv4(PointVector({ p2 }));

	*/
}