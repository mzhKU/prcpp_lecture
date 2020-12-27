
#include <iostream>
#include "Vater.h"
#include "Sohn.h"

using namespace std;

void Vater::foo(char c) {
    cout << "Vater::foo: " << c << endl;
}

void Sohn::foo(double a) {
    cout << "Sohn::foo: " << a << endl;
}

int main()
{
    Sohn s;
    s.foo('A');
}
