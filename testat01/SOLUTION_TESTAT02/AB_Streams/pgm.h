#pragma once

#include <string>
#include <vector>

using namespace std;

class PGM {
	vector<uint8_t> m_data;
	uint16_t m_width, m_height;
	uint8_t m_maxValue;
public:
	PGM();
	PGM(const vector<uint8_t> d, uint16_t w, uint16_t h, uint8_t maxValue);
	bool readASCII(const string& filename);
	bool writeBinary(const string& filename);
};