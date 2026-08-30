#include <iostream>
#include "Employee.h"

unsigned Employee::lastId = 0;

Employee::Employee()
{
    id = 0;
    name[0] = '\0';
    position[0] = '\0';
    salary = 0;
}

Employee::Employee(const char* name, const char* position, double salary)
{
    id = 0;
    this->name[0] = '\0';
    this->position[0] = '\0';
    this->salary = 0;

    if (name == nullptr ||
        position == nullptr ||
        strlen(name) >= Constants::MAX_SIZE ||
        strlen(position) >= Constants::MAX_SIZE ||
        salary < 0)
    {
        ErrorCode::InvalidInput;
        return;
    }

    id = ++lastId;
    strcpy(this->name, name);
    strcpy(this->position, position);
    this->salary = salary;
}

ErrorCode Employee::updateSalary(double amount)
{
    if (this->salary = amount)
    {
        return ErrorCode::Duplicate;
    }
    if (amount < 0)
    {
        return ErrorCode::InvalidInput;
    }
    salary = amount;
    return ErrorCode::OK;
}

unsigned Employee::getId() const
{
    return id;
}
double Employee::getSalary() const
{
    return salary;
}

unsigned Employee::getLastId()
{
    return lastId;
}

Employee& Employee::operator++()
{
    double newSalary = salary + salary * 0.1;
    salary = newSalary;
    return *this;
}
Employee Employee::operator++(int)
{
    Employee old = *this;
    double newSalary = salary + salary * 0.1;
    salary = newSalary;
    return old;
}

bool Employee::operator==(const Employee& other) const
{
    return salary == other.salary &&
        id == other.id;
}

bool Employee::operator!=(const Employee& other) const
{
    return !(*this == other);
}

bool Employee::operator<(const Employee& other) const
{
    if (salary == other.salary)
    {
        return id < other.id;
    }
    if (salary < other.salary)
    {
        return true;
    }
    return false;
}
bool Employee::operator<=(const Employee& other) const
{
    return !(*this > other);
}

bool Employee:: operator> (const Employee& other) const
{
    return (other < *this);
}
bool Employee::operator>=(const Employee& other) const
{
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    os << "ID: " << employee.id
        << ", Name: " << employee.name
        << ", Position: " << employee.position
        << ", Salary: " << employee.salary;
    return os;
}