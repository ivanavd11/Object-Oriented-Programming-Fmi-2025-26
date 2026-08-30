#include "Tennant.h"
#include <iostream>

Tennant::Tennant(const string& newFirst, const string& newSecond,
	shared_ptr<Apartment> newResidence) : firstName(newFirst), lastName(newSecond), residence(std::move(newResidence))
{
	if (this->residence)
	{
		this->residence->addTenant();
	}
}

Tennant::~Tennant()
{
	if (residence)
	{
		residence->removeTenant();
	}
}
const string& Tennant::getFirstName() const
{
	return firstName;
}
const string& Tennant::getLastName() const
{
	return lastName;
}
const shared_ptr<Apartment>& Tennant::getResidence() const
{
	return residence;
}

void Tennant::setFirstName(const std::string& newFirstName)
{
	if(newFirstName.size()>0)
	{
		this->firstName = newFirstName;
	}
}
void Tennant::setLastName(const std::string& newLastName)
{
	if (newLastName.size() > 0)
	{
		this->lastName = newLastName;
	}
}
void Tennant::setResidence(std::shared_ptr<Apartment> newResidence)
{
	changeResidence(std::move(newResidence));
}

void Tennant::changeResidence(std::shared_ptr<Apartment> newResidence)
{
	if (newResidence == residence)
	{
		return;
	}

	if (residence)
	{
		residence->removeTenant();
	}

	residence = std::move(newResidence);
	if (residence)
	{
		residence->addTenant();
	}
}

void Tennant::printInformation() const
{
	std::cout << firstName << ' ' << lastName;

	if (residence) {
		std::cout << " lives at "
			<< residence->getAddress();
	}
	else {
		std::cout << " has no residence";
	}

	std::cout << '\n';
}