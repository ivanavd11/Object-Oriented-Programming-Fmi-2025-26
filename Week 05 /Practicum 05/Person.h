#pragma once
#include "City.h"

enum class Color
{
	Brown,
	Green,
	Blue,
	Black,
	Unknown
};

class Person {
private:
	City birthplace;
	int age;
	Color eyeColor;

public:
	Person(const char* cityName,
		long population,
		int age,
		Color eyeColor);

	void print() const;
};
