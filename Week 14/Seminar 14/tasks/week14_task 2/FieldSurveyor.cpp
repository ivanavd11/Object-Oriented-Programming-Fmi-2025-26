#include "FieldSurveyor.h"
#include <stdexcept>
#include <iostream>

FieldSurveyor::FieldSurveyor(const std::string& name, int yearsExperience, const std::string& region)
	:Cartographer(name, yearsExperience), region(region)
{
	if (region.empty())
	{
		throw std::invalid_argument("Region cannot be empty");
	}
}
const std::string& FieldSurveyor::getRegion() const
{
	return region;
}

std::string FieldSurveyor::getRole() const
{
	return "Field Surveyor";
}
void FieldSurveyor::print() const
{
	std::cout << "Field Surveyor: " << getName()
		<< ", years of experience: " << getYears()
		<< ", region: " << getRegion() << "\n";
}
