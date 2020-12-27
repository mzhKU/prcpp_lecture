#pragma once

#include "Interface.h"
#include <string>

class Class : public Interface {
	std::string m_privateName;
public:
	Class(std::string name);
	virtual ~Class();
	void describe() override;
};