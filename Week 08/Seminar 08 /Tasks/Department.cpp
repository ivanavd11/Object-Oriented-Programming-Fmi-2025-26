#include <iostream>
#include "Department.h"
#include <cstring>

void Department::free()
{
	delete[] name;
	name = nullptr;
	delete[] employees;
	employees = nullptr;
	countOfEmployees = 0;
	capacity = 0;
}
void Department::copyFrom(const Department& other)
{
	if (other.name != nullptr)
	{
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
	else
	{
		name = nullptr;
	}
	countOfEmployees = other.countOfEmployees;
	capacity = other.capacity;

	if (capacity == 0)
	{
		employees = nullptr;
		return;
	}

	employees = new Employee[capacity];

	for (unsigned i = 0; i < countOfEmployees; i++)
	{
		employees[i] = other.employees[i];
	}

}
void Department::moveFrom(Department&& other)
{
	name = other.name;
	employees = other.employees;
	countOfEmployees = other.countOfEmployees;
	capacity = other.capacity;

	other.name = nullptr;
	other.employees = nullptr;
	other.countOfEmployees = 0;
	other.capacity = 0;
}
ErrorCode Department::resize(int newCap)
{
		if (newCap < countOfEmployees)
		{
			return ErrorCode::InvalidInput;
		}

		Employee* newEmployees =
			new Employee[newCap];

		for (unsigned i = 0;
			i < countOfEmployees;
			i++)
		{
			newEmployees[i] = employees[i];
		}

		delete[] employees;

		employees = newEmployees;
		capacity = newCap;

		return ErrorCode::OK;
	
}

double Department::averageSalary() const
{
	if (countOfEmployees == 0)
	{
		return 0;
	}
	double sum = 0.0;
	for (int i = 0; i < countOfEmployees; i++)
	{
		sum += employees[i].getSalary();
	}
	return sum / countOfEmployees;
}

Department::Department()
{
	name = nullptr;
	employees = nullptr;
	countOfEmployees = 0;
	capacity = 0;
}
Department::Department(const char* name, unsigned capacity)
{
	this->name = nullptr;
	employees = nullptr;

	countOfEmployees = 0;
	this->capacity = 0;

	if (name == nullptr ||
		strlen(name) == 0)
	{
		return;
	}
	
	this->name = new char[strlen(name) + 1];

	strcpy(this->name, name);

	if (capacity == 0)
	{
		capacity = 1;
	}
	this->capacity = capacity;
	employees = new Employee[capacity];

}
Department::Department(const Department& other)
{
	copyFrom(other);
}
Department::Department(Department&& other) noexcept
{
	moveFrom(std::move(other));
}
Department& Department::operator=(Department&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
Department& Department::operator=(const Department& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Department::~Department()
{
	free();
}

const char* Department::getName() const
{
	return name;
}
unsigned Department::getCountOfEmployees() const
{
	return countOfEmployees;
}

ErrorCode Department::addEmployee(const Employee& employee)
{
	if (employee.getId() == 0)
	{
		return ErrorCode::InvalidInput;
	}

	for (int i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].getId() == employee.getId())
		{
			return ErrorCode::Duplicate;
		}
	}

	if (countOfEmployees == capacity)
	{
		unsigned newCapacity = capacity == 0 ? 1 : capacity * 2;
		resize(newCapacity);
	}

	employees[countOfEmployees] = employee;
	countOfEmployees++;
	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(int id)
{
	if (id <= 0)
	{
		return ErrorCode::InvalidInput;
	}

	for (int i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].getId() == id)
		{
			for (unsigned j = i;j + 1 < countOfEmployees;j++)
			{
				employees[j] = employees[j + 1];
			}
			countOfEmployees--;
			return ErrorCode::OK;
		}
	}
	return ErrorCode::NotFound;
}

Employee& Department::operator[](int index)
{
	if (index >= countOfEmployees)
	{
		ErrorCode::InvalidInput;
		std::cout << "InvalidInput\n";
		return;
	}
	return employees[index];
}
const Employee& Department::operator[](int index) const
{
	if (index >= countOfEmployees)
	{
		ErrorCode::InvalidInput;
		std::cout << "InvalidInput\n";
		return;
	}
	return employees[index];
}

explicit Department::operator bool() const
{
	return countOfEmployees > 0;
}

Department& Department::operator()(double percent)
{
	if (percent < 0)
	{
		ErrorCode::InvalidInput;
		std::cout << "InvalidInput\n";
		return *this;
	}

	for (int i = 0; i < countOfEmployees; i++)
	{
		double newSalary = employees[i].getSalary() *(1+percent/100.0);
		employees[i].updateSalary(newSalary);
	}

	return *this;
}

bool Department::operator==(const Department& other) const
{
	return countOfEmployees ==other.countOfEmployees
		&&
		averageSalary() == other.averageSalary();
}

std::ostream& operator<<(std::ostream& os, const Department& department)
{
	os << "Department: " << (department.name ? department.name: "Unnamed")<< '\n';

	for (unsigned i = 0; i < department.countOfEmployees;i++)
	{
		os << "  " << department.employees[i] << '\n';
	}
	return os;
}