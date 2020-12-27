// EnumTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct ItemStuff {
    int v;
    friend std::ostream& operator<<(std::ostream& os, const ItemStuff& i) {
        return os << i.v;
    }
};


struct EnumTester {

    using thisIsTheItemStuffType = typename ItemStuff;

    thisIsTheItemStuffType a;
    thisIsTheItemStuffType b; 
    thisIsTheItemStuffType c; 

    enum struct thisIsTheEnumIdentifier {
        a, b, c
    };

};


int main()
{
    EnumTester et;
    std::cout << et.a << std::endl;
}
