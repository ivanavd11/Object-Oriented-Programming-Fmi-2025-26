#pragma once
#include "Department.h"

class Company {
private:
	Department departments[10];
	unsigned countOfDepartments;

	Company();

	int findDepartment(const char* name) const;

public:
	Company(const Company& other) = delete;
	Company(Company&& other) = delete;
	Company& operator=(const Company& other) = delete;
	Company& operator=(Company&& other) = delete;

	static Company& getInstance();

	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

	friend std::ostream& operator<<(std::ostream& os, const Company& company);

	explicit operator bool() const;

	Department* operator[](const char* departmentName);

	const Department* operator[](const char* departmentName) const;
};
