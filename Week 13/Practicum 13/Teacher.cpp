#include "Teacher.h"

Teacher::Teacher(const std::string& name, int age, const std::string& address, int years, double sallary)
	: Person(name, age, address), yearsOfTeaching(years), sallary(sallary)
{
	if (years < 0 || sallary < 0.0)
	{
		throw std::invalid_argument("Invalid input");
	}
}

int Teacher::getYears() const
{
	return yearsOfTeaching;
}
double Teacher::getSallary() const
{
	return sallary;
}

void Teacher::setYears(int newYears)
{
	if (newYears < 0)
	{
		throw std::invalid_argument("Years is negative");
	}
	yearsOfTeaching = newYears;
}
void Teacher::setSallary(double newSallary)
{
	if (newSallary < 0)
	{
		throw std::invalid_argument("Sallary is negative");
	}
	sallary = newSallary;
}

void Teacher::printInfo() const 
{
	Person::printInfo();

	std::cout << "Years of teaching: " << getYears()
		<< " with sallary: " << getSallary() << "\n";
}