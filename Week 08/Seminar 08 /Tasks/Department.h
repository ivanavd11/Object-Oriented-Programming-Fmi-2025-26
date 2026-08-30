#pragma once
#include "Employee.h"

class Department {
private:
	char* name;
	Employee* employees;
	unsigned countOfEmployees;
	unsigned capacity;

	void free();
	void copyFrom(const Department& other);
	void moveFrom(Department&& other);
	ErrorCode resize(int newCap);

	double averageSalary() const;

public:
	Department();
	Department(const char* name, unsigned capacity);
	Department(const Department& other);
	Department(Department&& other) noexcept;
	Department& operator=(Department&& other) noexcept;
	Department& operator=(const Department& other);
	~Department();

	const char* getName() const;
	unsigned getCountOfEmployees() const;

	ErrorCode addEmployee(const Employee& employee);

	ErrorCode removeEmployee(int id);

	friend std::ostream& operator<<(std::ostream& os, const Department& department);

	Employee& operator[](int index);
	const Employee& operator[](int index) const;

	Department& operator()(double percent);

	explicit operator bool() const;

	bool operator==(const Department& other) const;
};
