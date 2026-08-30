#include "Ruin.h"
#include <stdexcept>
#include <iostream>
#include <memory>

Ruin::Ruin(const std::string& name, int threat, const Coords& coords, const std::string& civilization)
	: Landmark(name, threat, coords), civilization(civilization)
{
	if (civilization.empty())
	{
		throw std::invalid_argument("Civilization cannot be empty");
	}
}

const std::string& Ruin::getCivilization() const
{
	return civilization;
}

std::string Ruin::getType() const
{
	return "Ruin";
}
void Ruin::print() const
{
	printBaseInfo();
	std::cout << ", civilization: " << civilization << "\n";
}

std::unique_ptr<Landmark> Ruin::clone() const
{
	return std::make_unique<Ruin>(*this);
}
