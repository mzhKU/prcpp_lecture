// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Header.h"
#include <memory>


int main()
{
    std::cout << "Hello World!\n";

    auto peter = std::make_shared<User>("Peter");
    auto vera = std::make_shared<User>("Vera");
    peter->obj = std::make_shared<Object>(1);
    peter->obj->owner = peter;
    vera->obj = peter->obj;

}