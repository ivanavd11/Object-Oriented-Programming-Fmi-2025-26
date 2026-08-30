#pragma once
#include <iostream>
#include <compare>
#include "ErrorCode.h"

namespace Constants {
	const int MAX_SIZE = 128;
}

class Employee {
private:
	unsigned id;
	char name[Constants::MAX_SIZE];
	char position[Constants::MAX_SIZE];
	double salary;

	static unsigned lastId;

public:
	Employee();
	Employee(const char* name, const char* position, double salary);

	ErrorCode updateSalary(double amount);
	unsigned getId() const;
	double getSalary() const;

	static unsigned getLastId();

	friend std::ostream& operator<<(std::ostream& os, const Employee& employee);

	bool operator==(const Employee& other) const;
	bool operator!=(const Employee& other) const;

	bool operator<(const Employee& other) const;
	bool operator<=(const Employee& other) const;

	bool operator>(const Employee& other) const;
	bool operator>=(const Employee& other) const;

	Employee& operator++();       // prefix
	Employee operator++(int);     // postfix


};
