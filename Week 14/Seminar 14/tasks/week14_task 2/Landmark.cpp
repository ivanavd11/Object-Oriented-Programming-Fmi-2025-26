#include "Landmark.h"
#include <stdexcept>
#include <iostream>

void Landmark::printBaseInfo() const
{
	std::cout <<"Type: "<<getType()
		<< ", name: " << getName()
		<< ", coordinates: (" << coords.x << ", " << coords.y << ")"
		<< ", threat: " << getThreat();
}

Landmark::Landmark(const std::string& name, int threat, const Coords& coords)
	: name(name), threat(threat), coords(coords)
{
	if (name.empty())
	{
		throw std::invalid_argument("Name cannot be empty");
	}
	if (threat < 0 || threat>10)
	{
		throw std::invalid_argument("Threat must be between 0 and 10");
	}
	if (coords.x < 0 || coords.y < 0)
	{
		throw std::invalid_argument("Coords must be positive");
	}
}

const std::string& Landmark::getName() const
{
	return name;
}
int Landmark::getThreat() const
{
	return threat;
}
Coords Landmark::getCoords() const
{
	return coords;
}