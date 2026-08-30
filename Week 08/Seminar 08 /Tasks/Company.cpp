#include "Company.h"
#include <iostream>
#include <cstring>

Company::Company()
{
    countOfDepartments = 0;
}

Company& Company::getInstance()
{
    static Company instance;
    return instance;
}

int Company::findDepartment(const char* name) const
{
    if (name == nullptr)
    {
        return -1;
    }

    for (unsigned i = 0;i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getName(),name) == 0)
        {
            return i;
        }
    }

    return -1;
}

ErrorCode Company::addDepartment(const char* name)
{
    if (name == nullptr || strlen(name)==0)
    {
        return ErrorCode::InvalidInput;
    }

    if (findDepartment(name) != -1)
    {
        return ErrorCode::Duplicate;
    }

    if (countOfDepartments >= 10)
    {
        return ErrorCode::Full;
    }
    departments[countOfDepartments] = Department(name, 0);
    countOfDepartments++;
    return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* name)
{
    if (name == nullptr || strlen(name) == 0)
    {
        return ErrorCode::InvalidInput;
    }

    if (findDepartment(name) == -1)
    {
        return ErrorCode::NotFound;
    }

    int index = findDepartment(name);

    for (int i = index; i<countOfDepartments-1;i++)
    {
        departments[i] = departments[i + 1];
    }
    countOfDepartments--;
    departments[countOfDepartments] = Department();
    return ErrorCode::OK;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
    int index = findDepartment(departmentName);

    if (index == -1)
    {
        return ErrorCode::NotFound;
    }

    return departments[index].addEmployee(employee);
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
    int index = findDepartment(departmentName);

    if (index == -1)
    {
        return ErrorCode::NotFound;
    }
    return departments[index].removeEmployee(id);
}

Department* Company::operator[](const char* departmentName)
{
    if (departmentName == nullptr || strlen(departmentName) == 0)
    {
        ErrorCode::InvalidInput;
        return nullptr;
    }
    int index = findDepartment(departmentName);
    if (index == -1)
    {
        ErrorCode::NotFound;
        return nullptr;
    }

    return &departments[index];
}

const Department* Company::operator[](const char* departmentName) const
{
    if (departmentName == nullptr || strlen(departmentName) == 0)
    {
        ErrorCode::InvalidInput;
        return nullptr;
    }
    int index = findDepartment(departmentName);
    if (index == -1)
    {
        ErrorCode::NotFound;
        return nullptr;
    }

    return &departments[index];
}

Company::operator bool() const
{
    for (int i = 0; i < countOfDepartments; i++)
    {
        if (departments[i])
        {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Company& company)
{
    os << "-----Company-----\n";
    for (int i = 0; i < company.countOfDepartments; i++)
    {
        os << company.departments[i] << '\n';
    }
    return os;
}