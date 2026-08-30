#pragma once
#include <string>

class Cipher {
private:
	std::string text;
public:
	Cipher(const std::string& newText);

	std::string encrypt() const;

	std::string operator[](size_t index) const;

	Cipher operator+(const Cipher& other) const;

	Cipher& operator+=(const Cipher& other);
};
