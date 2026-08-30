#include "Vehicle.h"
#include <stdexcept>

Vehicle::Vehicle(const std::string& registrationNumber)
	: registrationNumber(registrationNumber)
{
	if (registrationNumber.empty())
	{
		throw std::invalid_argument("Registration number cannot be empty");
	}
}

const std::string& Vehicle::getRegistrationNumber() const
{
	return registrationNumber;
}
