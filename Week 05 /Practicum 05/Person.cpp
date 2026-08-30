#include "Person.h"
#include <iostream>

Person::Person(const char* cityName,
	long population,
	int age,
	Color eyeColor): birthplace(cityName, population)
{
	this->age = age;
	this->eyeColor = eyeColor;
}

void Person::print() const
{
	std::cout << "Birthplace: "
		<< birthplace.getName() << std::endl;

	std::cout << "Population: "
		<< birthplace.getPopulation() << std::endl;

	std::cout << "Age: "
		<< age << std::endl;
}