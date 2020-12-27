#pragma once

// 2020_10_19_1_2, 20:00ff

struct C {
	char value;
	C();
	C(char);
	C(const C& c);
	// C& operator=(const C& c);
};