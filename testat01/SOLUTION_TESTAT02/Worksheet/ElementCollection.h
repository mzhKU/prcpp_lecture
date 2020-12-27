#pragma once

#include <memory>
#include "Element.h"

class ElementCollection {

	char letters[5] = { 'k', 'l', 'm', 'n', 'o' };


public:
	std::shared_ptr<Element[]> elements;
	ElementCollection();
	ElementCollection(const int i);
};