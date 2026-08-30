#include "Farmer.h"
#include <iostream>
#include <cstring>

using namespace std;

void Farmer::free()
{
	delete[] name;
	name = nullptr;
	nameSize = 0;

	delete[] plots;
	plots = nullptr;
	plotSize = 0;
}
void Farmer::copyFrom(const Farmer& other)
{
	if (other.name == nullptr || strlen(other.name) == 0 || other.nameSize == 0
		|| other.plots == nullptr || other.nameSize == 0)
	{
		cout << "Invalid input\n";

	}

	this->nameSize = other.nameSize;
	name = new char[nameSize + 1];
	strcpy(name, other.name);

	plotSize = other.plotSize;
	plots = new Plot * [plotSize];
	for (int i = 0; i < plotSize; i++)
	{
		plots[i] = other.plots[i];
	}

}
void Farmer::moveFrom(Farmer&& other)
{
	name = other.name;
	nameSize = other.nameSize;
	plots = other.plots;
	plotSize = other.plotSize;

	other.name = nullptr;
	other.nameSize = 0;
	other.plotSize = 0;
	other.plots = nullptr;
}

Farmer::Farmer(const char* name, size_t size, Plot** newplots, size_t plotssize)
{
	if (name == nullptr)
	{
		this->nameSize = 0;
		this->name = new char[1];
		this->name[0] = '\0';
	}
	else
	{
		this->name = new char[size + 1];
		this->nameSize = size;
		strcpy(this->name, name);
	}

	this->plotSize = plotssize;
	if (plotSize == 0)
	{
		this->plots = nullptr;
		return;
	}

	this->plots = new Plot * [plotSize];
	for (int i = 0; i < plotSize; i++)
	{
		plots[i] = newplots[i];
	}
}

Farmer::Farmer(const Farmer& other)
{
	copyFrom(other);
}
Farmer& Farmer::operator=(const Farmer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Farmer::Farmer(Farmer&& other) noexcept
{
	moveFrom(std::move(other));
}
Farmer& Farmer::operator=(Farmer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Farmer::~Farmer()
{
	free();
}

void Farmer::addPlot(Plot* plot)
{
	if (plot == nullptr)
	{
		cout << "Invalid plot!" << endl;
		return;
	}

	Plot** newPlots = new Plot * [plotSize + 1];
	for (int i = 0; i < plotSize; i++)
	{
		newPlots[i] = plots[i];
	}
	newPlots[plotSize] = plot;

	delete[] plots;
	plots = newPlots;
	plotSize++;
}

void Farmer::printField() const
{
	cout << "Farmer: " << name << endl;

	for (size_t i = 0; i < plotSize; i++)
	{
		if (plots[i] == nullptr)
		{
			continue;
		}
		cout << "Plot "
			<< plots[i]->getId()
			<< ": ";

		switch (plots[i]->getCropType())
		{
		case Crop::WHEAT: cout << "WHEAT"; break;

		case Crop::BARLEY: cout << "BARLEY"; break;

		case Crop::CORN: cout << "CORN"; break;

		case Crop::NOTHING: cout << "NOTHING"; break;
		}

		cout << endl;
	}
}