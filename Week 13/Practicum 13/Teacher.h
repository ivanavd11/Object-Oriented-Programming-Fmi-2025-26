#pragma once
#include "Person.h"
class Teacher : public Person
{
private:
	int yearsOfTeaching;
	double sallary;

public:
	Teacher(const std::string& name, int age, const std::string& address, int years, double sallary);

	int getYears() const;
	double getSallary() const;

	void setYears(int newYears);
	void setSallary(double newSallary);

	void printInfo() const override;
};

