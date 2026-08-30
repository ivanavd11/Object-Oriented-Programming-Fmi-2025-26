#include "Text.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void Text::free()
{
	delete[] text;
	text = nullptr;
	size = 0;
}
void Text::copyFrom(const Text& other)
{
	if (other.text == nullptr || other.size <= 0)
	{
		cout << "Invalid input\n";
		return;
	}

	size = other.size;
	text = new char[size];
	strcpy(text, other.text);

}
void Text::moveFrom(Text&& other)
{
	if (other.text == nullptr || other.size <= 0)
	{
		cout << "Invalid input\n";
		return;
	}
	size = other.size;
	text = other.text;
	other.size = 0;
	other.text = nullptr;
}

Text::Text()
{
	size_t len = strlen("Default message");
	text = new char[len + 1];
	size = len;
	strcpy(text, "Default message");
}
Text::Text(const char* newText, size_t newSize)
{
	if (newText == nullptr)
	{
		cout << "Invalid input\n";
		return;
	}

	if (strlen(newText) != newSize)
	{
		cout << "Invalid size\n";
		return;
	}

	size = newSize;
	text = new char[size + 1];
	strcpy(text, newText);
}

Text::Text(const Text& other)
{
	copyFrom(other);
}
Text& Text::operator=(const Text& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Text::Text(Text&& other) noexcept
{
	moveFrom(std::move(other));
}
Text& Text::operator=(Text&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Text::~Text()
{
	free();
}

char& Text::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		cout << "Invalid index\n";
		return;
	}

	return text[index];
}
const char& Text::operator[](int index) const
{
	if (index < 0 || index >= size)
	{
		cout << "Invalid index\n";
		return;
	}

	return text[index];
}

std::istream& operator>>(std::istream& in, Text& obj)
{
	string input;

	getline(in >> ws, input);

	char* newText = new char[input.size() + 1];

	strcpy(newText, input.c_str());

	delete[] obj.text;

	obj.text = newText;
	obj.size = input.size();

	return in;
}

std::ostream& operator<<(std::ostream& os, const Text& text)
{
	os << text.text;

	return os;
}