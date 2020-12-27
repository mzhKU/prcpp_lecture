// AB_Streams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "pgm.h"

int main() {

    PGM pgm;
    string filename       = "oie.pgm";
    string binaryFileName = "oie.bin.pgm";
    
    // pgm.readASCII(filename);
    // pgm.writeBinary(binaryFileName);

    string data{ "abc" };
    cout.put(data.at(0)) << endl;

    cout.put(10);
    cout.put(10);
    cout.put(10);
    cout.put(10);
}