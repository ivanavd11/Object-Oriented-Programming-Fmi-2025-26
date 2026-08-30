#pragma once
#include <string>

class Addable
{
public: 
	virtual void add(const std::string& toAdd) = 0;
	virtual ~Addable() = default;
};