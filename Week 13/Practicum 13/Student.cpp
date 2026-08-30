#include "Student.h"

Student::Student(const std::string& name, int age, const std::string& address, int semester)
	: Person(name, age, address), semester(semester)
{
	if (semester <= 0)
	{
		throw std::invalid_argument("Semester is negativ");
	}

}

int Student::getSemester() const
{
	return semester;
}
void Student::setSemester(int newSemester)
{
	if (newSemester <= 0)
	{
		throw std::invalid_argument("Semester is negativ");
	}
	semester = newSemester;
}

int Student::getCourse() const
{
	return semester / 2;
}

void Student::printInfo() const
{
	Person::printInfo();
	std::cout << "Course: "<< getCourse() << '\n';

	std::cout << "Semester: "<< semester << '\n';
}