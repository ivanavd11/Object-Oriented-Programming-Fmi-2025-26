#pragma once
#include <iostream>
class Person
{
private:
	std::string name;
	int age;
	std::string address;
public:
	Person(const std::string& name, int age, const std::string& address);

	const std::string& getName() const;
	int getAge() const;
	const std::string& getAddress() const;

	void setName(const std::string& newName);
	void setAge(int newAge);
	void setAddress(const std::string& newAddress);

	virtual void printInfo() const;

	virtual ~Person() = default;
};

