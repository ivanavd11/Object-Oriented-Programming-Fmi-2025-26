#include "NumbericalVector.h"
#include <iostream>

using namespace std;

void NumbericalVector::free()
{
	delete[] coordinates;
	size = 0;
	coordinates = nullptr;
}
void NumbericalVector::copyFrom(const NumbericalVector& other)
{
	this->size = other.size;

	if (size == 0)
	{
		coordinates = nullptr;
		return;
	}

	coordinates = new int[size];

	for (int i = 0; i < size; i++)
	{
		coordinates[i] = other.coordinates[i];
	}
}

NumbericalVector::NumbericalVector()
{
	size = 0;
	coordinates = nullptr;
}
NumbericalVector::NumbericalVector(int size)
{
	if (size < 0)
	{
		cout << "Invalid size\n";
		return;
	}
	this->size = size;

	if (size == 0)
	{
		coordinates = nullptr;
		return;
	}

	coordinates = new int[size];

	for (int i = 0; i < size; i++)
	{
		coordinates[i] = 0;
	}
}
NumbericalVector::NumbericalVector(const NumbericalVector& other)
{
	copyFrom(other);
}
NumbericalVector& NumbericalVector::operator=(const NumbericalVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
NumbericalVector::~NumbericalVector()
{
	free();
}

void NumbericalVector::setValue(int index, int val)
{
	if (index < 0 || index>=size)
	{
		cout << "Invalid Index\n";
		return;
	}

	coordinates[index] = val;
}

int& NumbericalVector::operator[](size_t index)
{
	if (index < 0 || index >= size)
	{
		cout << "Invalid Index\n";
		return;
	}
	return coordinates[index];
}
const int& NumbericalVector::operator[](size_t index) const
{
	if (index < 0 || index >= size)
	{
		cout << "Invalid Index\n";
		return;
	}
	return coordinates[index];
}

NumbericalVector NumbericalVector::operator+(const NumbericalVector& other)const
{
	if (this->size != other.size)
	{
		cout << "Vectors must have the same size!\n";
		return NumbericalVector();
	}
	NumbericalVector result(size);

	for (int i = 0; i < size; i++)
	{
		result.coordinates[i] =
			coordinates[i] + other.coordinates[i];
	}

	return result;
}
NumbericalVector& NumbericalVector::operator+= (const NumbericalVector & other)
{
	if (this->size != other.size)
	{
		cout << "Vectors must have the same size!\n";
		return *this;
	}
	for (int i = 0; i < size; i++)
	{
		coordinates[i] +=other.coordinates[i];
	}
	return *this;
}
int NumbericalVector::operator*(const NumbericalVector& other) const
{
	if (this->size != other.size)
	{
		cout << "Vectors must have the same size!\n";
		return -1;
	}

	int result;
	for (int i = 0; i < size; i++)
	{
		result += (coordinates[i] * other.coordinates[i]);
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const NumbericalVector& vector)
{
	os<< "[";
	for (int i = 0; i < vector.size;i++)
	{
		os << vector.coordinates[i];
		if (i != vector.size - 1)
		{
			os << ", ";
		}
	}

	os << "]";

	return os;
}

strong_ordering NumbericalVector::operator<=>(
	const NumbericalVector& other) const
{
	int minSize =
		size < other.size ? size : other.size;

	for (int i = 0; i < minSize; i++)
	{
		if (coordinates[i] < other.coordinates[i])
		{
			return strong_ordering::less;
		}

		if (coordinates[i] > other.coordinates[i])
		{
			return strong_ordering::greater;
		}
	}

	if (size < other.size)
	{
		return strong_ordering::less;
	}

	if (size > other.size)
	{
		return strong_ordering::greater;
	}

	return strong_ordering::equal;
}