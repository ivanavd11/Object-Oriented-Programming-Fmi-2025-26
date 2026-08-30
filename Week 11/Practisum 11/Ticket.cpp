#include "Ticket.h"
#include <iostream>

Ticket::Ticket(const string& name, double cost) : filmName(name), cost(cost) 
{
	if (filmName.empty()) 
	{
		std::cout << "Film name cannot be empty.\n";
	}

	if (cost < 0) 
	{
		std::cout << "Ticket cost cannot be negative.\n";
	}
}

const string& Ticket::getName() const
{
	return filmName;
}
double Ticket::getCost() const
{
	return cost;
}

void Ticket::setName(const string& newName)
{
	if (newName.empty())
	{
		std::cout << "Invalid newName\n";
		return;
	}
	this->filmName = newName;
}
void Ticket::setCost(double newCost)
{
	if (newCost < 0.0)
	{
		std::cout << "Invalid newCost\n";
		return;
	}
	this->cost = newCost;
}