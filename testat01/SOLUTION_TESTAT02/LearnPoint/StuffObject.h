#pragma once


void unique_test();

struct StuffObject {
	int val = 0;

public:

	StuffObject() : val{ 0 } {};
	StuffObject(int i) : val{ i } {};
	StuffObject(StuffObject& s) {
		val = s.val;
	}
};