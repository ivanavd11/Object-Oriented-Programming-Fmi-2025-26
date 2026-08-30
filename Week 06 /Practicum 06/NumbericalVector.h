#pragma once
#include <iostream>
#include <compare>
#include <cstddef>

class NumbericalVector {
private:
	int size;
	int* coordinates;

	void free();
	void copyFrom(const NumbericalVector& other);

public:
	NumbericalVector();
	NumbericalVector(int size);
	NumbericalVector(const NumbericalVector& other);
	NumbericalVector& operator=(const NumbericalVector& other);
	~NumbericalVector();

	void setValue(int index, int val);

	int& operator[](size_t index);
	const int& operator[](size_t index) const;

	NumbericalVector operator+(const NumbericalVector& other)const;
	NumbericalVector& operator+=(const NumbericalVector& other);
	int operator*(const NumbericalVector& other) const;

	friend std::ostream& operator<<(std::ostream& os, const NumbericalVector& vector);

	std::strong_ordering operator<=>(const NumbericalVector& other) const;
};
