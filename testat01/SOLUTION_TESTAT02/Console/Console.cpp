
#include <iostream>
#include <string.h>
#include <vector>

#include "../MySet/MySet.h"
#include "../MySet/OrderedSet.h"

class MemoryBlock {
public:
	std::vector<int> memory;
	MemoryBlock(initializer_list<int> vs) {
		for (const auto& v : vs) {
			memory.push_back(v);
		}
	}
	void f(MemoryBlock&&);
};
void f(MemoryBlock& notConstantParameter) {
	cout << "Not const parameter address = " << &notConstantParameter << endl;
}
void f(const MemoryBlock& constantParameter) {
	cout << "Const parameter address     = " << &constantParameter << endl;
}
void MemoryBlock::f(MemoryBlock&& variableParameter) {
	cout << "Variable parameter address  = " << &variableParameter << endl;
	size_t memoryIndex = 0;
	for (const auto& v : variableParameter.memory) {
		// cout << v << endl;
		if (v > 2) {
			variableParameter.memory[memoryIndex] = v;
			memoryIndex++;
		}
	}
}

int main() {
	OrderedSet s1({ 5,4,3,2,1 });
	OrderedSet s2 = s1.getLarger(2);
	OrderedSet s3 = s1.getSmaller(4);

	cout << s2 << endl;
	cout << s3 << endl;

	cout << s2.getSmaller(2) << endl;
}