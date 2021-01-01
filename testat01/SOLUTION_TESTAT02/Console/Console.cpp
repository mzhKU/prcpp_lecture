
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

	OrderedSet s1({ 1,2,3,20,13,9 });
	OrderedSet s2 = s1.getLarger(3);

	cout << s2 << endl;					// {9, 13, 20}
	cout << s2.getLarger(3) << endl;	// {1, 2, 3}

	/*
	OrderedSet s3 = s2.getLarger(3); // OrderedSet({ 9,13,20 })
	cout << s3 << endl;
	*/

	/*
	auto up = make_unique<int>();
	shared_ptr<int> sp;


	int emptyArrayWithSizeTwelveBytes[3];
	cout << "sizeof(emptyArrayWithSizeTwelveBytes) = " << sizeof(emptyArrayWithSizeTwelveBytes) << endl;
	emptyArrayWithSizeTwelveBytes[0] = 7;


	Set one({ 7, 9, 10, 11,  2,  8 });
	Set two({ 4, 6,  2,  3, 11, 10, 1 });
	Set intersectionOneTwo({ 11, 2, 10 });

	Set::intersection(one, std::move(two));
	cout << "two = " << two << endl;



	const MemoryBlock   memoryBlockConstant(      { 4, 5, 6 });
	      MemoryBlock   memoryBlockNotConstant(   { 1, 2, 3 });
		  MemoryBlock&& memoryBlockNamedRValueRef({ 1, 2, 3 }); // treated as lvalue

	f(memoryBlockConstant);
	f(memoryBlockNotConstant);
	f(memoryBlockNamedRValueRef);
	f(MemoryBlock({ 5, 6, 7 }));
	
	cout << "Before filter: " << endl;
	for (auto& v : memoryBlockNotConstant.memory) { cout << v << ", "; cout << endl; }
	
	// cast of lvalue to rvalue
	memoryBlockNotConstant.f(move(memoryBlockNotConstant));

	cout << "After filter: ";
	for (auto& v : memoryBlockNotConstant.memory) { cout << v << ", "; cout << endl; }

	*/

	// Set s(Set::difference(Set({ 1, 2, 3 }), Set({ 2, 3, 4 })));
}