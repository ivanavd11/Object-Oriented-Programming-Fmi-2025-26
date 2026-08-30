#include "City.h"
#include <iostream>
#include <cstring>
using namespace std;

void City::free()
{
	delete[]name;
	name = nullptr;
	population = 0;
}
void City::copyFrom(const City& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	population = other.population;
}

City::City()
{
	int len = strlen("Unknown");
	name = new char[len + 1];
	strcpy(name, "Unknown");
	population = 0;
}
City::City(const char* name, long newPopulation)
{
	population = newPopulation;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

}
City::City(const City& other)
{
	copyFrom(other);
}
City& City::operator=(const City& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return*this;
}
City::~City()
{
	free();
}

void City::setName(const char* name)
{
	delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void City::setPopulation(long population)
{
	if (population < 0)
	{
		cout << "Invalid population!" << endl;
		return;
	}

	this->population = population;
}

const char* City::getName() const
{
	return name;
}
long City::getPopulation() const
{
	return population;
}