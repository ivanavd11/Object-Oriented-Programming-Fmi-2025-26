#include "Cartographer.h"
#include <stdexcept>

Cartographer::Cartographer(const std::string& name, int yearsExperience)
	:name(name), yearsExperience(yearsExperience)
{
	if (name.empty())
	{
		throw std::invalid_argument("Name must be not empty");
	}
	if (yearsExperience < 0)
	{
		throw std::invalid_argument("Years of experience must be positive");
	}
}

const std::string& Cartographer::getName() const
{
	return name;
}
int Cartographer::getYears() const
{
	return yearsExperience;
}