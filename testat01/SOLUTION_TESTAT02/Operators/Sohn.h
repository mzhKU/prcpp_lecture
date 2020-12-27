#pragma once

class Sohn : public Vater {
public:
	using Vater::foo; // <-- Bietet die Methode mit 'char' an
	void foo(double);
};