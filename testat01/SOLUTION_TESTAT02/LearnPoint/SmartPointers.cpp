#include <memory>
#include <cassert>
#include "SmartPointers.h"
#include <string>

#include <iostream>

#include "StuffObject.h"

std::unique_ptr<StuffObject> factory(int val) {
	return std::make_unique<StuffObject>(val);
}

void unique_test() {
	auto up = factory(1);  // Ist keine Zuweisung, ist nur eine andere
	                       // Schreibweise für den aufruf eines Kontruktors
	                       // Person p = Person(77);  <=> Person q(77);
	                       // (unique_ptr hat keinen Zuweisungsoperator)
	
	// Möglich weil shared_ptr hat einen Zuweisungsoperator.
	std::shared_ptr<StuffObject> sp = factory(2); // sp ist der einzige der
	                                              // das Objekt auf dem Heap kennt.

	assert(sp.use_count() == 1);

	// auto up2 = up; Nicht erlaubt weil unique_ptr keinen
    //                Zuweisungsoperator hat.

	// std::shared_ptr<Object> sp2 = up; Nicht erlaubt weil up
	//                                   der alleinige Besitzer
	//                                   sein muss.

	/*
	sp = move(up); // Ownership von unique pointer wird auf shared pointer
	               // übertragen, nachher zeigt up nicht mehr auf das Objekt
	               // auf dem Heap.
	               // Es geht auch up2 = move(up), aber nicht mit Zuweisung. 

	assert(sp.use_count() == 1);
	assert(up.get() == nullptr);
	*/
}


/*
void another_unique_test() {
	auto up = factory(1);

}



void shared_test() {
	std::shared_ptr<std::string> s;
	
	{
		auto sp = std::make_shared<std::string>("shared");
	}
}
*/