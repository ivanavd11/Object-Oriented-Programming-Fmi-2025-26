#pragma once
#include "Person.h"

class Student : public Person
{
private:
	int semester;
public:
	Student(const std::string& name, int age, const std::string& address, int semester);

	int getSemester() const;
	void setSemester(int newSemester);

	int getCourse() const;

	void printInfo() const override;
};

