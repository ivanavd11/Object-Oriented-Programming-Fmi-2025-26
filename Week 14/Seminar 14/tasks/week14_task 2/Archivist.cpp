#include "Archivist.h"
#include <stdexcept>
#include <iostream>

Archivist::Archivist(const std::string& name, int yearsExperience, const std::string& institution)
	:Cartographer(name, yearsExperience), institution(institution)
{
	if (institution.empty())
	{
		throw std::invalid_argument("Institution cannot be empty");
	}
}

const std::string& Archivist::getInstitution() const
{
	return institution;
}

std::string Archivist::getRole() const
{
	return "Archivist";
}
void Archivist::print() const
{
	std::cout << "Archivist: " << getName()
		<< ", years of experience: " << getYears()
		<< ", institution: " << getInstitution() << "\n";
}