#pragma once
#include <string>
class Cartographer
{
	std::string name;
	int yearsExperience;
	
public:
	Cartographer(const std::string& name, int yearsExperience);

	const std::string& getName() const;
	int getYears() const;

	virtual std::string getRole() const = 0;
	virtual void print() const = 0;
	virtual ~Cartographer() = default;
};

