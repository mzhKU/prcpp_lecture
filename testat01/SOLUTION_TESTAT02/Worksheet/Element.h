#pragma once

#include <memory>
struct Element {
	char value;
	std::shared_ptr<Element> next;
	Element();
	Element(const char);	
};