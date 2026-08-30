#pragma once
#include <iostream>

class BinaryNumber
{
private:
	int* number;
	size_t size;

	void free();
	void copyFrom(const BinaryNumber& other);
	void moveFrom(BinaryNumber&& other);

	unsigned long long toDecimal() const;
	void fromDecimal(unsigned long long value);

public:
	BinaryNumber();
	BinaryNumber(unsigned long long decimal);

	BinaryNumber(const BinaryNumber& other);
	BinaryNumber(BinaryNumber&& other) noexcept;

	BinaryNumber& operator=(const BinaryNumber& other);
	BinaryNumber& operator=(BinaryNumber&& other) noexcept;

	~BinaryNumber();

	const int* getNumber() const;
	size_t getSize() const;

	void setNumber(const int* newNumber, size_t newSize);
	void setSize(size_t newSize);

	bool operator==(const BinaryNumber& other) const;

	BinaryNumber operator+(const BinaryNumber& other) const;
	BinaryNumber& operator+=(const BinaryNumber& other);

	friend std::ostream& operator<<(std::ostream& out, const BinaryNumber& binary);
};
