#include "Apartment.h"

Apartment::Apartment(const string& _address, int _numberOfRooms) : address(_address), numberOfRooms(_numberOfRooms) {
	numberOfTenants = 0;
}

const string& Apartment::getAddress() const
{
	return address;
}
int Apartment::getNumberOfRooms() const
{
	return numberOfRooms;
}

void Apartment::setAddress(const string& address)
{
	if (address.size()<=0)
	{
		return;
	}
	this->address = address;
}
void Apartment::setNumberOfRooms(int numberOfRooms)
{
	if (numberOfRooms <= 0)
	{
		return;
	}
	this->numberOfRooms = numberOfRooms;
}

int Apartment::getNumberOfTenants() const
{
	return numberOfTenants;
}
void Apartment::addTenant()
{
	numberOfTenants++;
}
void Apartment::removeTenant()
{
	if (numberOfTenants > 0)
	{
		numberOfTenants--;
	}
}