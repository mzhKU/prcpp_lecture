#include "pgm.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

PGM::PGM()
{}

PGM::PGM(const vector<uint8_t> d, uint16_t w=0, uint16_t h=0, uint8_t maxValue=0 ) :
    m_data{ d }, m_width{ w }, m_height{ h }, m_maxValue{ maxValue }
{}

bool PGM::readASCII(const string& filename)
{
    ifstream ifs;
    ifs.open(filename, ios::in);

    if (ifs.bad()) {
        cerr << "File could not be opened.";
        ifs.close();
        return false;
    }

    string pgmFormat;
    string currentLine;
    int currentValue;

    while (ifs) {
        
        getline(ifs, currentLine, '\n');

        // Skip all comments.
        while (ifs && currentLine[0] == '#') { getline(ifs, currentLine); }

        // Get Format.
        if (pgmFormat == "" && currentLine[0] == 'P') {
            pgmFormat == currentLine;
            continue;
        }

        // Skip all comments.
        while (ifs && currentLine[0] == '#') { getline(ifs, currentLine); }

        // Get Width and Height.
        stringstream ss(currentLine);
        ss >> m_width >> m_height;
        
        // Skip all comments.
        while (ifs && currentLine[0] == '#') { getline(ifs, currentLine); }

        // Get max value.
        if (m_maxValue == 0) {
            ifs >> m_maxValue;
            continue;
        }

        // Go to next non-empty line.
        while (ifs.get() != ' ') {}

        while (ifs >> currentValue) {
            uint8_t tmp;
            ifs >> tmp;
            m_data.emplace_back(tmp);
        }
    }

    ifs.close();
    return true;
}

bool PGM::writeBinary(const string& filename)
{
    ofstream ofs(filename, ios::binary | ios::out);

    if (!ofs.good()) {
        cerr << "Something went wrong with opening the file. Closing." << endl;
        ofs.close();
        return false;
    }

    // Parameters
    ofs << "P5" << endl;  // <-- solutions
    ofs << m_width << " " << m_height << endl;
    ofs << m_maxValue << endl;


    // Write data
    for (auto& k : m_data) {
        cout << "k = " << k << endl;
        // ofs.write(reinterpret_cast<char*>(&k), sizeof(k)); // <-- Official
        ofs.write((char*)k, sizeof(k)); // <-- my solution
    }
    

    ofs.close();
    return true;
}

