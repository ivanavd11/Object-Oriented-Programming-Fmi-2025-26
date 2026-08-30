#include "Settlement.h"
#include <stdexcept>
#include <iostream>
#include <memory>

Settlement::Settlement(const std::string& name, int threat, const Coords& coords, int population)
	:Landmark(name, threat, coords), population(population)
{
	if (population < 0)
	{
		throw std::invalid_argument("Population must be positive");
	}
}

int Settlement::getPopulation() const
{
	return population;
}

std::string Settlement::getType() const
{
	return "Settlement";
}

void Settlement::print() const 
{
	printBaseInfo();
	std::cout << ", population: " << population << '\n';
}

std::unique_ptr<Landmark> Settlement::clone() const
{
	return std::make_unique<Settlement>(*this);
}