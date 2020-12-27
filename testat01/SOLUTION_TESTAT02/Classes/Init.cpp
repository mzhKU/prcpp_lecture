#include <iostream>
#include <vector>

#include "Auto.h"
#include "StringContainer.h"
#include "Vec.cpp"
#include "Mutex.cpp"
#include "C.h"

using namespace std;

size_t strlen(const char s[]) {
	const char* p = s;
	while (*p++);
	return p - s - 1;
}

void strconcat(const char s1[], const char s2[], char*& res) {
	int lengthS1 = strlen(s1);
	int lengthS2 = strlen(s2);

	res = new char[lengthS1 + lengthS2 + 1];
	int i = 0;
	for (const char* c = s1; c < s1 + lengthS1; c++) {
		*(res + i) = *c; i++;
	}
	for (const char* c = s2; c < s2 + lengthS2; c++) {
		*(res + i) = *c; i++;
	}
	*(res + i) = '\0';

}

enum class COLOR { RED, YELLOW, GREEN};
enum class STATE { ON, OFF};

struct Ampel {
	STATE state;
	COLOR color;
};

#include <memory>

C foo(char v) {
	return C(v);
}

int main()
{
	string s1 = "Test";
	string&& r1 = move(s1);
	string&& r2 = s1 + "";

	C c('a');
	cout << "Address of initial c from main:                      &c = " << &c << endl;                  //
	cout << "Value of initial c from main before assignment: c.value = " << c.value << endl;
	c=foo('b');
	cout << "Address of initial c from main after assignment:    &c = " << &c << endl; //
	cout << "Value of initial c from main after assignment: c.value = " << c.value << endl;
}