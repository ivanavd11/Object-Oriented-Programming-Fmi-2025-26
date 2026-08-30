#include "BinaryNumber.h"
#include <iostream>

using namespace std;

void BinaryNumber::free()
{
	delete[] number;
	number = nullptr;
	size = 0;
}
void BinaryNumber::copyFrom(const BinaryNumber& other)
{
	if (other.size == 0 || other.number == nullptr)
	{
		cout << "invalid input\n";
		return;
	}

	number = new int[other.size];
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		number[i] = other.number[i];
	}
}
void BinaryNumber::moveFrom(BinaryNumber&& other)
{
	if (other.size == 0 || other.number == nullptr)
	{
		cout << "invalid input\n";
		return;
	}
	number = other.number;
	other.number = nullptr;
	size = other.size;
	other.size = 0;
}

BinaryNumber::BinaryNumber()
{
	size = 1;
	number = new int[size];
	number[0] = 0;
}

BinaryNumber::BinaryNumber(unsigned long long decimal)
{
	number = nullptr;
	size = 0;

	fromDecimal(decimal);
}

BinaryNumber::BinaryNumber(const BinaryNumber& other)
{
	copyFrom(other);
}
BinaryNumber::BinaryNumber(BinaryNumber&& other) noexcept
{
	moveFrom(std::move(other));
}

BinaryNumber& BinaryNumber::operator=(const BinaryNumber& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
BinaryNumber& BinaryNumber::operator=(BinaryNumber&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

BinaryNumber::~BinaryNumber()
{
	free();
}

void BinaryNumber::fromDecimal(unsigned long long value)
{
	delete[] number;
	if (value == 0)
	{
		size = 1;
		number = new int[size];
		number[0] = 0;
		return;
	}

	unsigned long long temp = value;
	size_t digits = 0;

	while (temp > 0)
	{
		digits++;
		temp = temp / 2;
	}

	size = digits;
	number = new int[size];
	for (int i = 0; i < size; i++)
	{
		number[size - i - 1] = value % 2;
		value = value / 2;
	}
}

const int* BinaryNumber::getNumber() const
{
	return number;
}
size_t BinaryNumber::getSize() const
{
	return size;
}

void BinaryNumber::setNumber(const int* newNumber, size_t newSize)
{
	if (newSize <= 0 || newNumber == nullptr)
	{
		cout << "Invalid input\n";
		return;
	}

	for (size_t i = 0; i < newSize; i++)
	{
		if (newNumber[i] != 0 && newNumber[i] != 1)
		{
			cout<< "Binary digits must be 0 or 1!\n";
			return;
		}
	}

	int* newData = new int[newSize];
	for (size_t i = 0; i < newSize; i++)
	{
		newData[i] = newNumber[i];
	}
	delete[] number;
	number = newData;
	size = newSize;
	delete[] newData;
}
void BinaryNumber::setSize(size_t newSize)
{
	if (newSize <= 0)
	{
		cout << "Invalid input\n";
		return;
	}
	int* newData = new int[newSize];

	for (size_t i = 0; i < newSize; i++)
	{
		newData[i] = 0;
	}

	size_t copyCount = newSize < size ? newSize : size;

	for (size_t i = 0; i < copyCount; i++)
	{
		newData[newSize - 1 - i] = number[size - 1 - i];
	}

	delete[] number;

	number = newData;
	size = newSize;
	delete[] newData;
}

unsigned long long BinaryNumber::toDecimal() const
{
	unsigned long long result = 0;

	for (int i = 0; i < size; i++)
	{
		result = result * 2 + number[i];
	}

	return result;
}

bool BinaryNumber::operator==(const BinaryNumber& other) const
{
	return toDecimal() == other.toDecimal();
}

BinaryNumber BinaryNumber::operator+(const BinaryNumber& other) const
{
	unsigned long long result = toDecimal() + other.toDecimal();

	return BinaryNumber(result);
}
BinaryNumber& BinaryNumber::operator+=(const BinaryNumber& other)
{
	unsigned long long result = toDecimal() + other.toDecimal();
	fromDecimal(result);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const BinaryNumber& binary)
{
	for (size_t i = 0; i < binary.size;i++)
	{
		out << binary.number[i];
	}

	return out;
}
