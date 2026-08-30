#include "Person.h"
#include <iostream>
#include <stdexcept>

Person::Person(const std::string& name, int age, const std::string& address)
	:name(name), age(age), address(address)
{
	if (age < 0 || age>120)
	{
		throw std::invalid_argument("Age is negativ");
	}
}

const std::string& Person::getName() const
{
	return name;
}
int Person::getAge() const
{
	return age;
}
const std::string& Person::getAddress() const
{
	return address;
}

void Person::setName(const std::string& newName)
{
	name = newName;
}
void Person::setAge(int newAge)
{
	if (newAge < 0 || newAge>120)
	{
		throw std::invalid_argument("Age is negativ");
	}
	age = newAge;
}
void Person::setAddress(const std::string& newAddress)
{
	address = newAddress;
}

void Person::printInfo() const
{
	std::cout << "Name: " << getName() << ", age: " << getAge() << ", address: " << getAddress() << "\n";
}
