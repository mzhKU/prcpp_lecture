#pragma once

template<int N>
class Factorial {
public:
	static constexpr int value = N*Factorial<N - 1>::value;
};


template<> class Factorial<1> {
public:
	static constexpr int value = 1;
};