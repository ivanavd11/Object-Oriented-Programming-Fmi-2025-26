#include "Temperature.h"
#include <iostream>
using namespace std;

int Temperature::toCelsius() const
{
	if (system == 'c')
	{
		return temperature;
	}

	return (temperature - 32) / 1.8;
}
int Temperature::toFahrenheit() const
{
	if (system == 'f')
	{
		return temperature;
	}

	return temperature * 1.8 + 32;
}

Temperature::Temperature(int newTemp, char newSystem)
{
	this->temperature = 0;
	this->system = 'c';

	setTemperature(newTemp);
	setSystem(newSystem);
}

int Temperature::getTemperature() const
{
	return temperature;
}
char Temperature::getSystem() const
{
	return system;
}

void Temperature::setTemperature(int newTemp)
{
	temperature = newTemp;
}
void Temperature::setSystem(char newSystem)
{
	if (newSystem != 'c' && newSystem != 'f')
	{
		cout << "Invalid system!" << endl;
		return;
	}

	this->system = newSystem;
}

bool Temperature::operator==(const Temperature& other) const
{
	return toCelsius() == other.toCelsius();
}
bool Temperature::operator<(const Temperature& other) const
{
	return toCelsius() < other.toCelsius();
}

bool Temperature::operator!=(const Temperature& other) const
{
	return !(*this==other);
}
bool Temperature::operator<=(const Temperature& other) const
{
	return !(other < *this);
}
bool Temperature::operator>(const Temperature& other) const
{
	return (other < *this);
}
bool Temperature::operator>=(const Temperature& other) const
{
	return!(*this < other);
}

Temperature Temperature::operator+ (const Temperature & other) const
{
	int result = toCelsius() + other.toCelsius();
	return Temperature(result, 'c');
}
Temperature Temperature::operator-(const Temperature& other) const
{
	int result = toCelsius() - other.toCelsius();
	return Temperature(result, 'c');
}

Temperature& Temperature::operator+=(const Temperature& other)
{
	if (this->system == 'c')
	{
		this->temperature += other.toCelsius();
	}
	else
	{
		this->temperature += other.toFahrenheit();
	}
	return *this;
}
Temperature& Temperature::operator-=(const Temperature& other)
{
	if (this->system == 'c')
	{
		this->temperature -= other.toCelsius();
	}
	else
	{
		this->temperature -= other.toFahrenheit();
	}
	return *this;
}