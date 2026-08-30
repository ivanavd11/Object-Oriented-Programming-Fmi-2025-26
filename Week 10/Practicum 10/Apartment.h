#pragma once
#include <string>
using namespace std;

class Apartment {
private:
	string address;
	int numberOfRooms;

	int numberOfTenants;

public:
	Apartment(const string& _address, int _numberOfRooms);

	const string& getAddress() const;
	int getNumberOfRooms() const;

	void setAddress(const string& address);
	void setNumberOfRooms(int numberOfRooms);

	int getNumberOfTenants() const;
	void addTenant();
	void removeTenant();

};
