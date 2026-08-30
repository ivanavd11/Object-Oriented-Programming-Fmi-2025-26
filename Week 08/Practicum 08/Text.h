#pragma once
#include <iostream>

class Text
{
private:
	char* text;
	size_t size;

	void free();
	void copyFrom(const Text& other);
	void moveFrom(Text&& other);

public:
	Text();
	Text(const char* newText, size_t newSize);

	Text(const Text& other);
	Text& operator=(const Text& other);

	Text(Text&& other) noexcept;
	Text& operator=(Text&& other) noexcept;

	~Text();

	char& operator[](int index);
	const char& operator[](int index) const;

	friend std::istream& operator>>(std::istream& is, Text& text);
	friend std::ostream& operator<<(std::ostream& os, const Text& text);
};
